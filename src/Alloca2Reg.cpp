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
#include "llvm/IR/Constants.h"
#include <set>
#include <map>

using namespace llvm;

namespace {
    struct Alloca2RegPass : public FunctionPass {
        static char ID;
        Alloca2RegPass() : FunctionPass(ID) {}

        //declare more varibles if you like
        std::set<AllocaInst*> TargetAllocas;
        std::map<BasicBlock*, std::map<AllocaInst*, Value*> > Post;
        std::map<BasicBlock*, std::map<AllocaInst*, PHINode*> > Pre;
        std::map<BasicBlock*, std::map<LoadInst*, PHINode*> > loads;
        std::map<BasicBlock*, std::set<std::pair<AllocaInst*, PHINode*> > > PHIs;

        Value *createPHIOrUndef(BasicBlock *bb, Type *type) {
            if (pred_size(bb))
                return PHINode::Create(type, pred_size(bb));
            else
                return UndefValue::get(type);
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
                                Value *val = createPHIOrUndef(bb, load->getType());
                                Post[bb][alloca] = val;
                                if (PHINode *phi = dyn_cast<PHINode>(val)) {
                                    Pre[bb][alloca] = phi;
                                    loads[bb][load] = phi;
                                    PHIs[bb].insert(std::pair<AllocaInst*, PHINode*>(alloca, phi));
                                } else
                                    load->replaceAllUsesWith(val);
                            }
                        }
                    }
                }
                for (auto it = TargetAllocas.begin(); it != TargetAllocas.end(); it++) {
                    AllocaInst *alloca = *it;
                    if (Post[bb].find(alloca) == Post[bb].end()) {
                        Value *val = createPHIOrUndef(bb, alloca->getAllocatedType());
                        Post[bb][alloca] = val;
                        if (PHINode *phi = dyn_cast<PHINode>(val)) 
                            PHIs[bb].insert(std::pair<AllocaInst*, PHINode*>(alloca, phi));
                    }
                }
            }
        }

        void fillPHIs(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                for (auto phi_it = PHIs[bb].begin(); phi_it != PHIs[bb].end(); phi_it++) {
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
                for (auto phi_it = PHIs[bb].begin(); phi_it != PHIs[bb].end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    phi->insertBefore(begin);
                }
                for (auto it = loads[bb].begin(); it != loads[bb].end(); it++) {
                    LoadInst *load = it->first;
                    PHINode *phi = it->second;
                    load->replaceAllUsesWith(phi);
                }
            }
        }

        void cleanUnused(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                std::set<std::pair<AllocaInst*, PHINode*> > removed;
                for (auto phi_it = PHIs[bb].begin(); phi_it != PHIs[bb].end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    if (phi->use_empty()) {
                        phi->eraseFromParent();
                        removed.insert(*phi_it);
                    }
                }
                for (auto it = removed.begin(); it != removed.end(); it++)
                    PHIs[bb].erase(*it);
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

        void cleanRedundant(Function &F) {
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                for (auto phi_it = PHIs[bb].begin(); phi_it != PHIs[bb].end(); phi_it++) {
                    AllocaInst *alloca = phi_it->first;
                    PHINode *phi = phi_it->second;
                    Value *val = phi->hasConstantValue();
                    if (val != nullptr) {
                        phi->replaceAllUsesWith(val);
                        phi->eraseFromParent();
                    }
                }
            }
        }

        virtual bool runOnFunction(Function &F) {
            errs() << "Working on function called " << F.getName() << "!\n";
            TargetAllocas.clear();
            Post.clear();
            Pre.clear();
            loads.clear();
            PHIs.clear();
            collectTargetAllocas(F);
            collectPosts(F);
            fillPHIs(F);
            insertPHIs(F);
            cleanUnused(F);
            cleanRedundant(F);
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