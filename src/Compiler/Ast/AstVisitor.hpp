#pragma once
#include <iostream>
#include <CSharpGrammarBaseVisitor.h>

class AstVisitor : public CSharpGrammarBaseVisitor
{
public:
    AstVisitor() = default;
    ~AstVisitor() = default;

    antlrcpp::Any visitProgram(CSharpGrammarParser::ProgramContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitExpressions(CSharpGrammarParser::ExpressionsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitAssign_statement(CSharpGrammarParser::Assign_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitLiteral(CSharpGrammarParser::LiteralContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitVar_def(CSharpGrammarParser::Var_defContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFunc_def(CSharpGrammarParser::Func_defContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitScope(CSharpGrammarParser::ScopeContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitReturn_statement(CSharpGrammarParser::Return_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitStatement(CSharpGrammarParser::StatementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFunc_call(CSharpGrammarParser::Func_callContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitArgs(CSharpGrammarParser::ArgsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitArg(CSharpGrammarParser::ArgContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitPars(CSharpGrammarParser::ParsContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitIf_statement(CSharpGrammarParser::If_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFor_statement(CSharpGrammarParser::For_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFor_condition(CSharpGrammarParser::For_conditionContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFor_operation(CSharpGrammarParser::For_operationContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitKw_statement(CSharpGrammarParser::Kw_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitPrint_statement(CSharpGrammarParser::Print_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitRead_statement(CSharpGrammarParser::Read_statementContext *ctx) override
    {
        return visitChildren(ctx);
    }
};