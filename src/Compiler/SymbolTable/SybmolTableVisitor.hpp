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

    antlrcpp::Any visitIf_statement(CSharpGrammarParser::If_statementContext *ctx) override;
    antlrcpp::Any visitFor_statement(CSharpGrammarParser::For_statementContext *ctx) override;
    antlrcpp::Any visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx) override;
    antlrcpp::Any visitFunc_def(CSharpGrammarParser::Func_defContext *ctx) override;
    antlrcpp::Any visitAssign_statement(CSharpGrammarParser::Assign_statementContext *ctx) override;
    antlrcpp::Any visitVar_def(CSharpGrammarParser::Var_defContext *ctx) override;
    antlrcpp::Any visitLiteral(CSharpGrammarParser::LiteralContext *ctx) override;
};