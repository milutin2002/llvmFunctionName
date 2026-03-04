cmake_minimum_required(VERSION 3.20)
project(FunctionNamesPass)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})


add_library(FunctionNamesPass MODULE pass.cpp)


target_link_libraries(FunctionNamesPass LLVM)

set_target_properties(FunctionNamesPass PROPERTIES
    CXX_STANDARD 17
    PREFIX ""        
)