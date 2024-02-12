find_package(Java COMPONENTS Runtime REQUIRED)

############ Generate runtime #################
# macro to add dependencies to target
#
# Param 1 project name
# Param 1 namespace (postfix for dependencies)
# Param 2 Lexer file (full path)
# Param 3 Parser File (full path)
#
# output
#
# antlr4cpp_src_files_{namespace} - src files for add_executable
# antlr4cpp_include_dirs_{namespace} - include dir for generated headers
# antlr4cpp_generation_{namespace} - for add_dependencies tracking

macro(antlr4cpp_process_grammar
    antlr4cpp_project
    antlr4cpp_project_namespace
    antlr4cpp_grammar_parser)

  if(EXISTS "${ANTLR4CPP_JAR_LOCATION}")
    message(STATUS "Found antlr tool: ${ANTLR4CPP_JAR_LOCATION}")
  else()
    message(FATAL_ERROR "Unable to find antlr tool. ANTLR4CPP_JAR_LOCATION:${ANTLR4CPP_JAR_LOCATION}")
  endif()

  set(antlr4cpp_include_dirs_${antlr4cpp_project} ${CMAKE_CURRENT_BINARY_DIR}/${antlr4cpp_project})
  set(antlr4cpp_src_files_${antlr4cpp_project} ${antlr4cpp_project}Listener.cpp ${antlr4cpp_project}BaseListener.cpp ${antlr4cpp_project}BaseVisitor.cpp ${antlr4cpp_project}Visitor.cpp ${antlr4cpp_project}Parser.cpp ${antlr4cpp_project}Lexer.cpp)
  list(TRANSFORM antlr4cpp_src_files_${antlr4cpp_project} PREPEND ${CMAKE_CURRENT_BINARY_DIR}/${antlr4cpp_project}/)

  add_custom_command(OUTPUT ${antlr4cpp_src_files_${antlr4cpp_project}}
    COMMAND
    "${Java_JAVA_EXECUTABLE}" -jar "${ANTLR4CPP_JAR_LOCATION}" -Dlanguage=Cpp -listener -visitor -o "${antlr4cpp_project}" -package ${antlr4cpp_project_namespace} "${antlr4cpp_grammar_parser}"
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    DEPENDS "${antlr4cpp_grammar_parser}")
endmacro()
