#include "llvm/Support/CommandLine.h"
#include "ASTChecker.h"
#include "ASTBuilder.h"
#include "Program.h"
#include "ASTPrinter.h"
#include "VerifyAndBuildSymbols.h"
#include "IRGenerator.h"
#include "llvm/IR/Module.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/Host.h"

using namespace llvm;

cl::opt<std::string> InputFileName(cl::Positional, cl::desc("<input file>"), cl::Required);
cl::opt<bool> CheckANTLRParseTree("check-parse-tree", cl::desc("Check ANTLR parse tree and quit"));
cl::opt<bool> PrintAST("print-ast", cl::desc("Print AST parse tree"));
cl::opt<bool> PrintIR("print-ir", cl::desc("Print Bitcode IR"));
cl::opt<std::string> OutputFileName("o", cl::desc("Output file"), cl::value_desc("filename"), cl::init("output.bc"));

int main(int arc, char **argv) {
    cl::ParseCommandLineOptions(arc, argv);

    if (CheckANTLRParseTree.getValue()) {
        checkASTStatus(InputFileName.getValue());
        return 0;
    }

    minicc::Program* prog = buildAST(InputFileName.getValue());

    if (!prog)
        return 1;

    if (PrintAST.getValue()) {
        minicc::ASTPrinter visitor;
        visitor.visitProgram(prog);
    }

    minicc::VerifyAndBuildSymbols verifier;
    verifier.visitProgram(prog);

    if (verifier.numErrors() > 0) {
        errs() << verifier.genErrorMessages();
        return 1;
    }

    minicc::IRGenerator generator(OutputFileName.getValue());
    generator.visitProgram(prog);
    std::unique_ptr<llvm::Module> m = generator.getModule();
    m->setTargetTriple(sys::getDefaultTargetTriple());

    if (PrintIR.getValue()) {
        m->print(outs(), nullptr);
    }

    std::error_code EC;
    llvm::raw_fd_ostream OS(OutputFileName, EC);
    llvm::WriteBitcodeToFile(*m, OS);
    OS.flush();

    delete prog;

    return 0;
}
