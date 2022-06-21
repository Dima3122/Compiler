#include "SybmolTableVisitor.hpp"

std::map<int, Node> SybmolTableVisitor::GetSymbolTable()
{
    return SybmolTable;
}

antlrcpp::Any SybmolTableVisitor::visitVar_def(CSharpGrammarParser::Var_defContext *ctx)
{
    auto text = ctx->VAR()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->VAR()->getText(), "Var", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFunc_def(CSharpGrammarParser::Func_defContext *ctx)
{
    auto text = ctx->ID()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->ID()->getText(), "Func", 0, ctx->getStart()->getLine()));
    for (auto item : ctx->pars()->var_def())
    {
        auto text = item->VAR()->getText() + std::to_string(ctx->getStart()->getLine());
        SybmolTable.emplace(Node::GetHash(text), Node(text, item->VAR()->getText(), "Var", 0, ctx->getStart()->getLine()));
    }
    text = ctx->return_statement()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->return_statement()->getText(), "ReturnStatement", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitIf_statement(CSharpGrammarParser::If_statementContext *ctx)
{
    auto text = ctx->IF()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->IF()->getText(), "If", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx)
{
    auto text = ctx->ELSE()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->ELSE()->getText(), "Else", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFor_statement(CSharpGrammarParser::For_statementContext *ctx)
{
    auto text = ctx->FOR()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->FOR()->getText(), "ForLoop", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitPrint_statement(CSharpGrammarParser::Print_statementContext *ctx)
{
    auto text = ctx->WRITELN()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->WRITELN()->getText(), "Func", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitRead_statement(CSharpGrammarParser::Read_statementContext *ctx)
{
    auto text = ctx->READLN()->getText() + std::to_string(ctx->getStart()->getLine());
    SybmolTable.emplace(Node::GetHash(text), Node(text, ctx->READLN()->getText(), "Func", 0, ctx->getStart()->getLine()));
    return visitChildren(ctx);
}