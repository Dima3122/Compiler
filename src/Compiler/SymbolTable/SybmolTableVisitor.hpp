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

    antlrcpp::Any visitProgram(CSharpGrammarParser::ProgramContext *ctx) override;
    antlrcpp::Any visitExpressions(CSharpGrammarParser::ExpressionsContext *ctx) override;
    antlrcpp::Any visitAssign_statement(CSharpGrammarParser::Assign_statementContext *ctx) override;
    antlrcpp::Any visitLiteral(CSharpGrammarParser::LiteralContext *ctx) override;
    antlrcpp::Any visitVar_def(CSharpGrammarParser::Var_defContext *ctx) override;
    antlrcpp::Any visitFunc_def(CSharpGrammarParser::Func_defContext *ctx) override;
    antlrcpp::Any visitScope(CSharpGrammarParser::ScopeContext *ctx) override;
    antlrcpp::Any visitReturn_statement(CSharpGrammarParser::Return_statementContext *ctx) override;
    antlrcpp::Any visitStatement(CSharpGrammarParser::StatementContext *ctx) override;
    antlrcpp::Any visitFunc_call(CSharpGrammarParser::Func_callContext *ctx) override;
    antlrcpp::Any visitArgs(CSharpGrammarParser::ArgsContext *ctx) override;
    antlrcpp::Any visitArg(CSharpGrammarParser::ArgContext *ctx) override;
    antlrcpp::Any visitPars(CSharpGrammarParser::ParsContext *ctx) override;
    antlrcpp::Any visitIf_statement(CSharpGrammarParser::If_statementContext *ctx) override;
    antlrcpp::Any visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx) override;
    antlrcpp::Any visitFor_statement(CSharpGrammarParser::For_statementContext *ctx) override;
    antlrcpp::Any visitFor_condition(CSharpGrammarParser::For_conditionContext *ctx) override;
    antlrcpp::Any visitFor_operation(CSharpGrammarParser::For_operationContext *ctx) override;
    antlrcpp::Any visitKw_statement(CSharpGrammarParser::Kw_statementContext *ctx) override;
    antlrcpp::Any visitPrint_statement(CSharpGrammarParser::Print_statementContext *ctx) override;
    antlrcpp::Any visitRead_statement(CSharpGrammarParser::Read_statementContext *ctx) override;
};