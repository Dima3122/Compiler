add_library(grammar STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarLexer.cpp 
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarParser.cpp
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarBaseVisitor.cpp
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarVisitor.cpp)

target_link_libraries(grammar PRIVATE antlr4_cpp_runtime)

set(SOURCE_FILES
	Compiler/main.cpp
	Compiler/SymbolTable/Node.cpp
	Compiler/SymbolTable/SybmolTableVisitor.cpp
	Compiler/Semantic/SemanticVisitor.cpp
	Compiler/Ast/Ast.cpp
	Compiler/Ast/AstVisitor.hpp
)

add_executable(compiler_exe ${SOURCE_FILES})

target_link_libraries(compiler_exe PRIVATE cxxopts)
target_link_libraries(compiler_exe PRIVATE grammar)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)