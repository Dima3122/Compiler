#include <CsharpLexer.h>
#include <CsharpParser.h>
#include <CsharpBaseVisitor.h>
#include "Parser/Parser.hpp"
#include "Semantic/SemanticVisitor.hpp"
#include "CodeGen/CodeGen.hpp"
#include <cxxopts.hpp>
#include <antlr4-runtime.h>
#include <string>
#include <iostream>
#include <cstdio>

using namespace antlr4;

int main(int argc, const char *argv[])
{
    // setup and parse options
    cxxopts::Options options("Lexer", "Lexical analyzer");
    options.add_options()("d,dump-tokens", "Dump tokens",
                          cxxopts::value<bool>()->default_value("false"))(
        "f,file", "File name", cxxopts::value<std::string>());
    options.allow_unrecognised_options();
    const auto args = options.parse(argc, argv);

    if (args.count("file") != 1)
    {
        return 0;
    }
    // create lexer
    std::string filename = args["file"].as<std::string>();
    ANTLRFileStream input(filename);
    CsharpLexer lexer(&input);

    // Option --dump-tokens
    if (args["dump-tokens"].as<bool>())
    {
        auto item = lexer.nextToken();
        while (item->getType() != item->EOF)
        {
            std::cout << "Loc=<" << item->getLine() << ":"
                      << item->getCharPositionInLine() << "> "
                      << lexer.getVocabulary().getSymbolicName(item->getType())
                      << " "
                      << "\'" << item->getText() << "\'" << std::endl;
            item = lexer.nextToken();
        }
    }

    CommonTokenStream tokens(&lexer);

    CsharpParser parser(&tokens);
    parser.setBuildParseTree(true);
    antlr4::tree::ParseTree *tree = parser.program();
    //std::cout << tree->toStringTree() << std::endl;
    
    // parser.expression();
    // std::cout << parser.Const << std::endl;
    // std::cout << parser.expression()->toStringTree() << std::endl;
    // SybmolTableVisitor semantic_visitor;
    // semantic_visitor.visit(tree);
    // for (auto item: semantic_visitor.GetSymbolTable())
    // {
    //     item.second.print(); 
    // }
    //Visitor astVisitor;
    return 0;
}