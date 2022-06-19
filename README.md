# Compiler

java -jar ./antlr4/antlr-4.9.1-complete.jar -Dlanguage=Cpp ./src/Grammar/CSharpGrammar.g4 -o ./src/Grammar/antlr4-parser-grammar -Xexact-output-dir -lib ./src/Grammar -lib ./src/Grammar/antlr4-parser-grammar -no-listener -visitor