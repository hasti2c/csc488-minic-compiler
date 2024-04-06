cmake_minimum_required(VERSION 3.14)

add_library(ast ASTChecker.cpp ASTChecker.h GrammarStatVisitor.cpp GrammarStatVisitor.h ASTChecker.h ASTNode.h Program.h Declarations.h Statements.h Exprs.h Terms.h ASTVisitor.h ASTVisitor.cpp Exprs.cpp ASTBuilder.cpp ASTBuilder.h ASTPrinter.h Types.h ASTNode.cpp VerifyAndBuildSymbols.h VerifyAndBuildSymbols.cpp SymbolTable.h)

add_library(irgen IRGenerator.cpp IRGenerator.h ASTVisitor.h Exprs.h Statements.h Terms.h Program.h Declarations.h ASTNode.h SymbolTable.h)

add_executable(minicc main.cpp)
add_dependencies(minicc ast irgen)
# fno-rtti is required to work with LLVM related components, but not with ANTLR
target_compile_options(minicc PRIVATE -fno-rtti)
target_link_directories(minicc PRIVATE ${LLVM_CMAKE_DIR}/../..)
llvm_map_components_to_libnames(llvm_libs support bitwriter core)
target_link_libraries(minicc PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/libirgen.a ${CMAKE_CURRENT_BINARY_DIR}/libast.a ${llvm_libs} grammar ${ANTLR4_LIB_DIR}/libantlr4-runtime.a)

add_library(alloca2reg MODULE Alloca2Reg.cpp)
target_compile_options(alloca2reg PRIVATE -fno-rtti)
add_library(algsimplify MODULE AlgSimplify.cpp)
target_compile_options(algsimplify PRIVATE -fno-rtti)

# Get proper shared-library behavior (where symbols are not necessarily
# resolved when the shared library is linked) on OS X.
if(APPLE)
    set_target_properties(alloca2reg PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
            )
endif(APPLE)
