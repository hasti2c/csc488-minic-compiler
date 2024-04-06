//
// Created by Fan Long on 2020/12/9.
//

//add more header files if your want
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Constants.h"
#include <set>
#include <map>
#include <iostream> // TODO

using namespace llvm;

namespace {
    struct AlgSimplifyPass : public FunctionPass {
        static char ID;
        AlgSimplifyPass() : FunctionPass(ID) {}

        std::map<BinaryOperator*, Value*> TargetInstrs;

        Value *simplified(BinaryOperator *bin) {
            Instruction::BinaryOps opcode = bin->getOpcode();
            Value *op1 = bin->getOperand(0), *op2 = bin->getOperand(1);
            if (!isa<ConstantInt>(op1) && !isa<ConstantInt>(op2))
                return nullptr;
            
            switch (opcode) {
            case Instruction::Add:
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op1)) {
                    if (cnst->isZero())
                        return op2;
                }
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op2)) {
                    if (cnst->isZero())
                        return op1;
                }
                break;
            case Instruction::Sub:
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op2)) {
                    if (cnst->isZero())
                        return op1;
                }
                break;
            case Instruction::Mul:
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op1)) {
                    if (cnst->isZero())
                        return cnst;
                    else if (cnst->isOne())
                        return op2;
                }
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op2)) {
                    if (cnst->isZero())
                        return cnst;
                    else if (cnst->isOne())
                        return op1;
                }
                break;
            case Instruction::SDiv:
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op1)) {
                    if (cnst->isZero())
                        return cnst;
                }
                if (ConstantInt *cnst = dyn_cast<ConstantInt>(op2)) {
                    if (cnst->isOne())
                        return op1;
                }
                break;
            }
            return nullptr;
        }

        void collectTargetInstrs(Function &F) {
           //start your code here 
            for (Function::iterator bb_it = F.begin(); bb_it != F.end(); bb_it++) {
                BasicBlock *bb = (BasicBlock*) &*bb_it;
                for (BasicBlock::iterator inst = bb->begin(); inst != bb->end(); inst++)
                    if (BinaryOperator *bin = dyn_cast<BinaryOperator>(inst)) {
                        Value *val = simplified(bin);
                        if (val != nullptr)
                            TargetInstrs[bin] = val;
                    }
            }
        }

        void replaceUsesInTargetInstrs(Value *old, Value *newVal) {
            for (auto it = TargetInstrs.begin(); it != TargetInstrs.end(); it++) {
                BinaryOperator *bin = it->first;
                Value *val = it->second;
                if (val == old)
                    TargetInstrs[bin] = newVal;
            }
        }

        void simplifyTargetInstrs(Function &F) {
            for (auto it = TargetInstrs.begin(); it != TargetInstrs.end(); it++) {
                BinaryOperator *bin = it->first;
                Value *val = it->second;
                bin->replaceAllUsesWith(val);
                replaceUsesInTargetInstrs(bin, val);
            }
        }

        void cleanUnused(Function &F) {
            for (auto it = TargetInstrs.begin(); it != TargetInstrs.end(); it++) {
                BinaryOperator *bin = it->first;
                if (bin->use_empty())
                    bin->eraseFromParent();
            }
        }

        virtual bool runOnFunction(Function &F) {
            while (true) {
                TargetInstrs.clear();
                collectTargetInstrs(F);
                if (TargetInstrs.empty())
                    break;
                simplifyTargetInstrs(F);
                cleanUnused(F);
            }
            return true;
        }
    };
}

char AlgSimplifyPass::ID = 0;

static RegisterPass<AlgSimplifyPass> X("algsimplify", "Algebraic Simplification pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlgSimplify(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new AlgSimplifyPass());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlgSimplify);