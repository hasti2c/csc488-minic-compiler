cmake_minimum_required(VERSION 3.14)
project(minicc)

find_package(LLVM 15 REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.11.1-complete.jar)
# add antrl4cpp artifacts to project environment
include(Antlr4Cpp)

#find_package(antlr4-runtime 4.11.1 REQUIRED
#        PATHS
#        . /usr/local/Cellar)
#May be useful to replace with find_package for antlr4-runtime
set(ANTLR4_INCLUDE_DIR /usr/local/include/antlr4-runtime)
#set(ANTLR4_LIB_DIR /usr/lib/x86_64-linux-gnu)
set(ANTLR4_LIB_DIR /usr/local/lib)

message("Antlr Include Dir: " ${ANTLR4_INCLUDE_DIR})
message("Antlr Library Dir: " ${ANTLR4_LIB_DIR})

if(EXISTS ${PROJECT_SOURCE_DIR}/build)
    # this is to make many IDE happy about getting the header file. Need to use "build" directory though
    include_directories( ${LLVM_INCLUDE_DIRS} ${ANTLR4_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/build)
else()
    include_directories( ${LLVM_INCLUDE_DIRS} ${ANTLR4_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)
endif()
add_definitions(${LLVM_DEFINITIONS})
link_directories( ${ANTLR4_LIBS_DIR} )

# Mac OS would require this to build
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(grammars)
add_subdirectory(src)
add_subdirectory(minicio)
