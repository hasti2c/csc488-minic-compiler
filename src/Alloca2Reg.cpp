//
// Created by Fan Long on 2020/12/9.
//

//add more header files if your want
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include <set>
#include <map>
#include <iostream> // TODO

using namespace llvm;

namespace {
    struct Alloca2RegPass : public FunctionPass {
        static char ID;
        Alloca2RegPass() : FunctionPass(ID) {}

        //declare more varibles if you like
        std::set<AllocaInst*> TargetAllocas;
        std::map<BasicBlock*, std::map<AllocaInst*, Value*> > Post;
        std::map<BasicBlock*, std::map<AllocaInst*, PHINode*> > Pre;
        std::map<LoadInst*, PHINode*> loadPHIs;

        std::set<std::pair<AllocaInst*, PHINode*> > getPHINodes(BasicBlock* bb) { // TODO: global var
            std::set<std::pair<AllocaInst*, PHINode*> > phis;
            for (auto it = Pre[bb].begin(); it != Pre[bb].end(); it++)
                phis.insert(*it);
            for (auto it = Post[bb].begin(); it != Post[bb].end(); it++)
                if (PHINode *phi = dyn_cast<PHINode>(it->second))
                    phis.insert(std::pair<AllocaInst*, PHINode*>(it->first, phi));
            return phis;
        }

        void collectTargetAllocas(Function &F) {
           //start your code here 
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                for (BasicBlock::iterator inst = bb->begin(); inst != bb->end(); inst++)
                    if (AllocaInst *alloca = dyn_cast<AllocaInst>(inst))
                        if (alloca->getAllocatedType()->isIntegerTy())
                            TargetAllocas.insert(alloca);
            }
        }

        void collectPosts(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                for (BasicBlock::iterator inst = bb->begin(); inst != bb->end(); inst++) {
                    if (StoreInst *store = llvm::dyn_cast<StoreInst>(inst)) {
                        AllocaInst *alloca = (AllocaInst*) store->getPointerOperand();
                        if (TargetAllocas.find(alloca) != TargetAllocas.end())
                            Post[bb][alloca] = store->getValueOperand();
                    } else if (LoadInst *load = llvm::dyn_cast<LoadInst>(inst)) {
                        AllocaInst *alloca = (AllocaInst*) load->getPointerOperand();
                        if (TargetAllocas.find(alloca) != TargetAllocas.end()) {
                            if (Post[bb].find(alloca) != Post[bb].end())
                                load->replaceAllUsesWith(Post[bb][alloca]);
                            else {
                                PHINode *phi = PHINode::Create(load->getType(), pred_size(bb));
                                Pre[bb][alloca] = phi;
                                Post[bb][alloca] = phi;
                                loadPHIs[load] = phi;
                            }
                        }
                    }
                }
                for (auto it = TargetAllocas.begin(); it != TargetAllocas.end(); it++) {
                    AllocaInst *alloca = *it;
                    if (Post[bb].find(alloca) == Post[bb].end())
                        Post[bb][alloca] = PHINode::Create(alloca->getAllocatedType(), pred_size(bb));
                }
            }
        }

        void fillPHIs(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                std::set<std::pair<AllocaInst*, PHINode*> > phis = getPHINodes(bb);
                for (auto phi_it = phis.begin(); phi_it != phis.end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    for (auto pred_it = predecessors(bb).begin(); pred_it != predecessors(bb).end(); pred_it++) {
                        BasicBlock *pred = *pred_it;
                        phi->addIncoming(Post[pred][alloca], pred);
                    }
                }
            }
        }

        void insertPHIs(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                Instruction *begin = (Instruction*) &*(bb->begin());
                std::set<std::pair<AllocaInst*, PHINode*> > phis = getPHINodes(bb);
                for (auto phi_it = phis.begin(); phi_it != phis.end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    phi->insertBefore(begin);
                }
            }
            for (auto it = loadPHIs.begin(); it != loadPHIs.end(); it++) {
                LoadInst *load = it->first;
                PHINode *phi = it->second;
                load->replaceAllUsesWith(phi);
            }
        }

        void cleanUnused(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                std::set<std::pair<AllocaInst*, PHINode*> > phis = getPHINodes(bb);
                for (auto phi_it = phis.begin(); phi_it != phis.end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    if (phi->use_empty())
                        phi->eraseFromParent();
                }
            }
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                std::set<Instruction*> removeable;
                for (BasicBlock::iterator inst_it = bb->begin(); inst_it != bb->end(); inst_it++) {
                    AllocaInst *alloca;
                    Instruction *inst = &*inst_it;
                    if (LoadInst *load = dyn_cast<LoadInst>(inst)) {
                        alloca = (AllocaInst*) load->getPointerOperand();
                    } else if (StoreInst *store = dyn_cast<StoreInst>(inst)) {
                        alloca = (AllocaInst*) store->getPointerOperand();
                    } else {
                        continue;
                    }

                    if (TargetAllocas.find(alloca) != TargetAllocas.end()) {
                        removeable.insert(inst);
                        inst->dropAllReferences();
                    }
                }
                for (auto it = removeable.begin(); it != removeable.end(); it++) {
                    if ((*it)->use_empty())
                        (*it)->eraseFromParent();
                }
            }
            for (auto it = TargetAllocas.begin(); it != TargetAllocas.end(); it++)
                (*it)->eraseFromParent();
        }

        virtual bool runOnFunction(Function &F) {
            errs() << "Working on function called " << F.getName() << "!\n";
            TargetAllocas.clear();
            Post.clear();
            Pre.clear();
            loadPHIs.clear();
            collectTargetAllocas(F);
            //start your code here
            collectPosts(F);
            fillPHIs(F);
            insertPHIs(F);
            cleanUnused(F);
            return true;
        }
    };
}

char Alloca2RegPass::ID = 0;

static RegisterPass<Alloca2RegPass> X("alloca2reg", "Alloca-to-register pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlloca2RegPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new Alloca2RegPass());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlloca2RegPass);