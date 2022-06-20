#include "SybmolTableVisitor.hpp"

antlrcpp::Any SybmolTableVisitor::visitProgram(CSharpGrammarParser::ProgramContext *ctx)
{
    std::cout << "visitProgram" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitExpressions(CSharpGrammarParser::ExpressionsContext *ctx)
{
    std::cout << "visitExpressions" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitAssign_statement(CSharpGrammarParser::Assign_statementContext *ctx)
{
    std::cout << "visitAssign_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitLiteral(CSharpGrammarParser::LiteralContext *ctx)
{
    std::cout << "visitLiteral" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitVar_def(CSharpGrammarParser::Var_defContext *ctx)
{
    std::cout << "visitVar_def" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFunc_def(CSharpGrammarParser::Func_defContext *ctx)
{
    std::cout << "visitFunc_def" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitScope(CSharpGrammarParser::ScopeContext *ctx)
{
    std::cout << "visitScope" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitReturn_statement(CSharpGrammarParser::Return_statementContext *ctx)
{
    std::cout << "visitReturn_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitStatement(CSharpGrammarParser::StatementContext *ctx)
{
    std::cout << "visitStatement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFunc_call(CSharpGrammarParser::Func_callContext *ctx)
{
    std::cout << "visitFunc_call" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitArgs(CSharpGrammarParser::ArgsContext *ctx)
{
    std::cout << "visitArgs" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitArg(CSharpGrammarParser::ArgContext *ctx)
{
    std::cout << "visitArg" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitPars(CSharpGrammarParser::ParsContext *ctx)
{
    std::cout << "visitPars" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitIf_statement(CSharpGrammarParser::If_statementContext *ctx)
{
    std::cout << "visitIf_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx)
{
    std::cout << "visitElse_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFor_statement(CSharpGrammarParser::For_statementContext *ctx)
{
    std::cout << "visitFor_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFor_condition(CSharpGrammarParser::For_conditionContext *ctx)
{
    std::cout << "visitFor_condition" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitFor_operation(CSharpGrammarParser::For_operationContext *ctx)
{
    std::cout << "visitFor_operation" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitKw_statement(CSharpGrammarParser::Kw_statementContext *ctx)
{
    std::cout << "visitKw_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitPrint_statement(CSharpGrammarParser::Print_statementContext *ctx)
{
    std::cout << "visitPrint_statement" << std::endl;
    return visitChildren(ctx);
}
antlrcpp::Any SybmolTableVisitor::visitRead_statement(CSharpGrammarParser::Read_statementContext *ctx)
{
    std::cout << "visitRead_statement" << std::endl;
    return visitChildren(ctx);
}