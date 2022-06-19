add_library(grammar STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarLexer.cpp 
						   ${CMAKE_CURRENT_SOURCE_DIR}/Grammar/antlr4-parser-grammar/CSharpGrammarParser.cpp)

target_link_libraries(grammar PRIVATE antlr4_cpp_runtime)

set(SOURCE_FILES
	Compiler/main.cpp	
)

add_executable(compiler_exe ${SOURCE_FILES})

target_link_libraries(compiler_exe PRIVATE cxxopts)
target_link_libraries(compiler_exe PRIVATE grammar)