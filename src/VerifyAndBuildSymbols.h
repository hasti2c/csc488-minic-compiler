//
// Created by Fan Long on 2020/12/4.
//

#ifndef MINICC_VERIFYANDBUILDSYMBOLS_H
#define MINICC_VERIFYANDBUILDSYMBOLS_H

#include "ASTVisitor.h"
#include "ASTNode.h"
#include <vector>
#include <string>

namespace minicc {

    struct ErrorMessage {
        std::string Msg;
        SourceLocation SrcLoc;

        ErrorMessage(const std::string &msg, const SourceLocation &srcLoc) : Msg(msg), SrcLoc(srcLoc) { }
    };

    class VerifyAndBuildSymbols : public ASTVisitor {
        std::vector<ErrorMessage> Errors;
        Program* VisitingProgram;
    public:

        VerifyAndBuildSymbols() : Errors(), VisitingProgram(nullptr) { }

        size_t numErrors() {
            return Errors.size();
        }

        std::string genErrorMessages();

        void visitASTNode(ASTNode *node) override;

        void visitProgram(Program *prog) override;

        void visitVarDecl(VarDeclaration *decl) override;

        void visitFuncDecl(FuncDeclaration *func) override;

        void visitIfStmt(IfStatement *stmt) override;

        void visitForStmt(ForStatement *stmt) override;

        void visitContinueStmt(ContinueStatement *stmt) override;

        void visitReturnStmt(ReturnStatement *stmt) override;

        void visitBreakStmt(BreakStatement *stmt) override;

        void visitUnaryExpr(UnaryExpr *expr) override;

        void visitBinaryExpr(BinaryExpr *expr) override;

        void visitCallExpr(CallExpr *expr) override;

        void visitVarExpr(VarExpr *expr) override;

        void visitAssignmentExpr(AssignmentExpr *expr) override;

        void visitIntLiteralExpr(IntLiteralExpr *literal) override;

        void visitBoolLiteralExpr(BoolLiteralExpr *literal) override;

        void visitCharLiteralExpr(CharLiteralExpr *literal) override;
    };
}

#endif //MINICC_VERIFYANDBUILDSYMBOLS_H
