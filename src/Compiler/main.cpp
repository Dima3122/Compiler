#include <CsharpLexer.h>
#include <CsharpParser.h>
#include <CsharpBaseListener.h>
#include "Parser/Parser.hpp"
#include "Semantic/SemanticVisitor.hpp"
#include "CodeGen/CodeGen.hpp"
#include <CLI/CLI.hpp>
#include <antlr4-runtime.h>
#include <string>
#include <iostream>
#include <cstdio>

#define VERSION "0.0.1"

std::string exec(const char *cmd)
{
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
    {
        return "ERROR";
    }
    char buffer[128];
    std::string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
        {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

int main(int argc, const char *argv[])
{

    CLI::App app;
    std::string filepath;
    std::string fileout = "../examples/file.ll";
    std::string xml_file = "";
    bool dump_tokens_key = false;
    bool version_key = false;
    bool dump_ast = false;
    bool dump_tab = false;
    bool dump_sem = false;
    bool dump_asm = false;
    bool optim1 = false;
    bool wall = false;
    app.add_flag("--dump-tokens", dump_tokens_key, "Dump func");
    app.add_flag("--dump-ast", dump_ast, "Dump ast");
    app.add_flag("--dump-table", dump_tab, "Dump table");
    app.add_flag("--dump-semantic", dump_sem, "Dump semantic report");
    app.add_flag("--dump-asm", dump_asm, "Dump LLVM IR");
    app.add_flag("--version", version_key, "Version func");
    app.add_flag("--opt", optim1, "Unable optimization");
    app.add_flag("--wall", wall, "Warnings info");
    auto fileflag = app.add_option("-f, --file", filepath, "Filepath");
    app.add_option("-o, --out", fileout, "Out file");
    app.add_option("-x, --to-xml", xml_file, "Filepath XML");
    fileflag->needs(fileflag);
    CLI11_PARSE(app, argc, argv);
    if (version_key)
    {
        std::cout << VERSION << '\n';
    }
    auto parse_result = cs_lang::parse_test(filepath);
    if (!parse_result.m_errors.empty())
    {
        cs_lang::dump_errors(parse_result.m_errors);
        return -1;
    }
    VisitorTable visitor;
    parse_result.m_program->accept(visitor);

    if (dump_tab)
    {
        cs_lang::dump_table(visitor);
    }

    if (dump_tokens_key)
    {
        cs_lang::dump_tokens(filepath);
    }
    SemanticVisitor semantic_visitor(visitor.get_table(), visitor.get_fprops(), visitor.get_indexer(), visitor.get_inner_table());
    parse_result.m_program->accept(semantic_visitor);

    if (semantic_visitor.get_errors().size() > 0)
    {
        cs_lang::print_semantic_report(semantic_visitor);
        exit(EXIT_FAILURE);
    }

    if (dump_ast || xml_file != "")
    {
        cs_lang::dump_ast(parse_result.m_program, xml_file, dump_ast);
    }
    std::ofstream stream(fileout + ".ll");
    CodeGen code_generator(stream, filepath, fileout + ".ll");
    parse_result.m_program->accept(code_generator);
    stream.close();
    std::string llc_command = "llc-14 " + fileout + ".ll && clang-14 -o " + fileout + " " + fileout + ".s -no-pie";

    exec(llc_command.c_str());
    if (dump_asm)
    {
        std::string line;
        std::ifstream ll(fileout);
        if (ll.is_open())
        {
            while (std::getline(ll, line))
            {
                std::cout << line << '\n';
            }
            ll.close();
        }
    }
    return 0;
}