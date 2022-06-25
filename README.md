# С# compiler written in C++
1. Download ANTLR: wget -P ./antlr4 https://www.antlr.org/download/antlr-4.9.1-complete.jar
2. Generate grammar java -jar ./antlr4/antlr-4.9.1-complete.jar -Dlanguage=Cpp ./src/Grammar/Csharp.g4 -o ./src/Grammar/antlr4-parser-grammar -Xexact-output-dir -lib ./src/Grammar -lib ./src/Grammar/antlr4-parser-grammar -no-listener -visitor
3. Configure CMake: cmake -B ./build -DCMAKE_BUILD_TYPE=Debug
4. Build: cmake --build ./build --config Debug

# Launch Options
1. --dump-tokens -> Вывод токенов в терминал
2. --dump-table  -> Вывод таблицы символов в терминал
3. --dump-asm    -> Вывод llvm ir в терминал
4. --out, -o     -> Куда сохранять ll файл.

# Launch 
1. ./bin/compiler_exe -f ./examples/hello.cs -o ./examples/hello.ll
clang-14 -o <Имя выходного файла> <Ассемблерный файл> -no-pie