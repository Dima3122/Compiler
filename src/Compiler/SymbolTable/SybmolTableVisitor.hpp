#pragma once
#include <iostream>
#include <CSharpGrammarBaseVisitor.h>
#include "Node.hpp"

class SybmolTableVisitor: public CSharpGrammarBaseVisitor
{
private:
    std::map<int, Node> SybmolTable;
public:
    SybmolTableVisitor() = default;
    ~SybmolTableVisitor() = default;

    std::map<int, Node> GetSymbolTable();

    antlrcpp::Any visitVar_def(CSharpGrammarParser::Var_defContext *ctx) override;
    antlrcpp::Any visitFunc_def(CSharpGrammarParser::Func_defContext *ctx) override;
    antlrcpp::Any visitIf_statement(CSharpGrammarParser::If_statementContext *ctx) override;
    antlrcpp::Any visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx) override;
    antlrcpp::Any visitFor_statement(CSharpGrammarParser::For_statementContext *ctx) override;
    antlrcpp::Any visitPrint_statement(CSharpGrammarParser::Print_statementContext *ctx) override;
    antlrcpp::Any visitRead_statement(CSharpGrammarParser::Read_statementContext *ctx) override;
};