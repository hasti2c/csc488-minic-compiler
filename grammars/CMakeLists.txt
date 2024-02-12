cmake_minimum_required(VERSION 3.14)

# Build prog grammar parsers
antlr4cpp_process_grammar(MiniC minicc
    ${CMAKE_CURRENT_SOURCE_DIR}/MiniC.g4)

add_library(grammar OBJECT ${antlr4cpp_src_files_MiniC})
target_include_directories(grammar PRIVATE ${antlr4cpp_include_dirs_MiniC} ${ANTLR4_INCLUDE_DIR})