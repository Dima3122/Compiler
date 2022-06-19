# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

include(cmake/CompileOptions.cmake)

project(CSharp-compiler)

include_directories(
    ${PROJECT_SOURCE_DIR}/submodules/antlr4-cpp-runtime/runtime/src
    ${PROJECT_SOURCE_DIR}/src/Grammar/antlr4-parser-grammar
)

add_subdirectory(submodules)
add_subdirectory(src)
