//
// Created by Fan Long on 2020/12/4.
//

//Add necessary headers you want
#include "VerifyAndBuildSymbols.h"
#include "Declarations.h"
#include "Terms.h"
#include "Types.h"
#include "Exprs.h"
#include "Statements.h"
#include "Program.h"
#include <string>
#include <sstream>

namespace minicc {

    void VerifyAndBuildSymbols::visitASTNode(ASTNode *node) {
        //start your code here
        //Hint: set root of the node before visiting children
    }

    void VerifyAndBuildSymbols::visitProgram(Program *prog) {
        //start your code here
        if (prog->syslibFlag()) {
            // Manually populate the function symbol table
            // ...
        }
    }

    void VerifyAndBuildSymbols::visitVarDecl(VarDeclaration *decl) {
        //start your code here
        //Hint: Check that same variable cannot be declared twice in the same scope
    }

    void VerifyAndBuildSymbols::visitFuncDecl(FuncDeclaration *func) {
        //start your code here
        //Hint: Check return type of the function does not match with each other
        //      Check number of parameters should match with each other
        //      Check each parameter type should match with each other
        //      Check there should be only one definition of the function
        //      Check parameters cannot have the same name
        //      Check the last statement a function body must be return if the return type is not void
    }

    void VerifyAndBuildSymbols::visitIfStmt(IfStatement *stmt) {
        //start your code here
        //Hint: Check the conditional expression must have bool type
    }

    void VerifyAndBuildSymbols::visitForStmt(ForStatement *stmt) {
        //start your code here
        //Hint: Check the second expression in for must be either null or bool type
    }

    void VerifyAndBuildSymbols::visitContinueStmt(ContinueStatement *stmt) {
        //start your code here
        //Hint: Check Continue statement must appear inside a for statement
    }

    void VerifyAndBuildSymbols::visitReturnStmt(ReturnStatement *stmt) {
        //start your code here
        //Hint: Check void function must have no expression to return
        //      Check Non-Void function must have an expression to return
        //      Check the return type and the returned expression type must match
    }

    void VerifyAndBuildSymbols::visitBreakStmt(BreakStatement *stmt) {
        //start your code here
        //Hint: Check Break statement must appear inside a for statement
    }

    void VerifyAndBuildSymbols::visitUnaryExpr(UnaryExpr *expr) {
        //start your code here
        //Hint: Check Negate opcode must have int operand!
        //      Check Not opcode must have bool operand
    }

    void VerifyAndBuildSymbols::visitBinaryExpr(BinaryExpr *expr) {
        //start your code here
        //Hint: Check that for logical opcode, both operand need to be bool
        //      Check that for equal and not equal opcode, both operand need to be the same primitive types
        //      Check that for arithmetic and other comparison operand, both operand need to be int
    }

    void VerifyAndBuildSymbols::visitCallExpr(CallExpr *expr) {
        //start your code here
        //Hint: Check Call undeclared function
        //      Check the number of arguments must match the number of parameters
        //      Check the type of each parameter must match the argument
    }

    static Type verifyVarReference(std::vector<ErrorMessage> & Errors, Expr* expr, VarReference *ref) {
        //start your code here
        //Hint: Check the vairable which is reference must be declared before
        //      Check index expression must have int type
        //      Check variable must be declared as an array for indexing
        //return ref Type
        return Type(Type::Void);
    }

    void VerifyAndBuildSymbols::visitVarExpr(VarExpr *expr) {
        //start your code here
        //Hint: invoke verifyVarReference to verify
    }

    void VerifyAndBuildSymbols::visitAssignmentExpr(AssignmentExpr *expr) {
        //start your code here
        //Hint: invoke verifyVarReference to verify
        //      Also, check var and assigned expression must have the same type
    }

    void VerifyAndBuildSymbols::visitIntLiteralExpr(IntLiteralExpr *literal) {
        //start your code here
        //Hint: Check Integer literal must be inside the range of int
    }

    void VerifyAndBuildSymbols::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        //start your code here
    }

    void VerifyAndBuildSymbols::visitCharLiteralExpr(CharLiteralExpr *literal) {
        //start your code here
    }

    //print collected error messages
    std::string VerifyAndBuildSymbols::genErrorMessages() {
        std::stringbuf buf;
        std::ostream os(&buf);

        for (size_t i = 0; i < Errors.size(); i++) {
            os << Errors[i].Msg << " (" << Errors[i].SrcLoc.Line << ":" << Errors[i].SrcLoc.Row << ")\n";
        }

        return buf.str();
    }

}