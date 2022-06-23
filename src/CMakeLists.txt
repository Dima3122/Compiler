add_library(grammar STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CsharpLexer.cpp 
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CsharpParser.cpp
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CsharpBaseVisitor.cpp
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CsharpVisitor.cpp)

target_link_libraries(grammar PRIVATE antlr4_cpp_runtime)

set(SOURCE_FILES
	Compiler/main.cpp
	Compiler/Ast/Ast.cpp
	Compiler/SymbolTable/SybmolTableVisitor.cpp
	Compiler/Semantic/SemanticVisitor.cpp
	Compiler/CodeGen/CodeGen.cpp
	Compiler/Parser/Parser.cpp
)

add_executable(compiler_exe ${SOURCE_FILES})

target_link_libraries(compiler_exe PRIVATE CLI11)
target_link_libraries(compiler_exe PRIVATE cxxopts)
target_link_libraries(compiler_exe PRIVATE grammar)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)