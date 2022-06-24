#include "Parser.hpp"
#include <CsharpLexer.h>
#include <CsharpParser.h>
#include "../SymbolTable/SybmolTableVisitor.hpp"
#include <CLI/CLI.hpp>
#include <antlr4-runtime.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace cs_lang
{
    class StreamErrorListener : public antlr4::BaseErrorListener
    {
    public:
        void syntaxError(
            antlr4::Recognizer *,
            antlr4::Token *,
            size_t line,
            size_t column,
            const std::string &message,
            std::exception_ptr) override
        {
            m_errors.emplace_back(Error{line, column, message});
        }

        const Errors &errors() const { return m_errors; }

    private:
        Errors m_errors;
    };

    void dump_errors(Errors &errors)
    {
        for (const auto &error : errors)
        {
            std::cerr << "ERROR <" << error.m_line << ", " << error.m_column << ">: " << error.m_message << "\n";
        }
    }

    void dump_ast(ASTProgram *program, std::string xml_file, bool print_key)
    {
        bool delete_tmp = false;
        if (xml_file == "")
        {
            delete_tmp = true;
            xml_file = "../../examples/tmp.xml";
        }

        std::ofstream stream(xml_file);
        VisitorTraverse visitor_print(stream);
        program->accept(visitor_print);
        stream.close();
        std::string line;
        std::ifstream myfile(xml_file);
        if (print_key)
        {
            if (myfile.is_open())
            {
                while (std::getline(myfile, line))
                {
                    std::cout << line << '\n';
                }
                myfile.close();
            }
            if (delete_tmp)
            {
                std::remove("../../examples/tmp.xml");
            }
        }
    }

    void dump_table(VisitorTable table)
    {
        table.print_table();
    }

    tokens_array dump_tokens(std::string filepath, int print_key)
    {
        std::ifstream stream;
        tokens_array tokens;
        stream.open(filepath);
        if (stream.is_open() == false)
        {
            std::cerr << "Error: " << filepath
                      << ": No such file or directory\n";

            return tokens;
        }

        antlr4::ANTLRInputStream input(stream);

        CsharpLexer lexer(&input);

        auto vocabulary = lexer.getVocabulary();
        while (true)
        {
            auto tkn = lexer.nextToken();
            if (tkn->getText() == "<EOF>")
            {
                break;
            }
            if (print_key)
            {
                std::cout << "Loc=<"
                          << tkn->getLine() << ", "
                          << tkn->getCharPositionInLine() << "> "
                          << vocabulary.getSymbolicName(tkn->getType())
                          << " \'" << tkn->getText() << "\'\n";
            }
            tokens.push_back(tkn->getLine(), tkn->getCharPositionInLine(), vocabulary.getSymbolicName(tkn->getType()), tkn->getText());
        }
        return tokens;
    }

    ParseResult parse_test(std::string filepath)
    {
        std::ifstream stream(filepath);
        if (!stream.is_open())
        {
            throw "Error: FileNotFound\n";
        }

        antlr4::ANTLRInputStream input(stream);
        CsharpLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);
        CsharpParser parser(&tokens);

        StreamErrorListener error_listener;
        parser.removeErrorListeners();
        parser.addErrorListener(&error_listener);

        antlrcpp::Any program = parser.program();

        auto &errors = error_listener.errors();
        if (!errors.empty())
        {
            return ParseResult::errors(errors);
        }

        VisitorInitialiser visitor_init(program);

        ASTProgram *ast = new ASTProgram;
        ast->accept(visitor_init);
        return ParseResult::program(ast);
    }

}
