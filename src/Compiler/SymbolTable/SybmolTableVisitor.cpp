#include "SybmolTableVisitor.hpp"

antlrcpp::Any SybmolTableVisitor::visitIf_statement(CSharpGrammarParser::If_statementContext *ctx)
{
    std::cout << "visitIf_statement" << std::endl;
    return 0;
}
antlrcpp::Any SybmolTableVisitor::visitFor_statement(CSharpGrammarParser::For_statementContext *ctx)
{
    std::cout << "visitFor_statement" << std::endl;
    return 0;
}
antlrcpp::Any SybmolTableVisitor::visitElse_statement(CSharpGrammarParser::Else_statementContext *ctx)
{
    std::cout << "visitElse_statement" << std::endl;
    return 0;
}
antlrcpp::Any SybmolTableVisitor::visitFunc_def(CSharpGrammarParser::Func_defContext *ctx)
{
    std::cout << "visitFunc_def" << std::endl;
    return 0;
}
antlrcpp::Any SybmolTableVisitor::visitAssign_statement(CSharpGrammarParser::Assign_statementContext *ctx)
{
    std::cout << "visitAssign_statement" << std::endl;
    return 0;
}
antlrcpp::Any SybmolTableVisitor::visitVar_def(CSharpGrammarParser::Var_defContext *ctx)
{
    std::cout << "visitVar_def" << std::endl;
    return 0;
}

antlrcpp::Any SybmolTableVisitor::visitLiteral(CSharpGrammarParser::LiteralContext *ctx)
{
    std::cout << "visitLiteral" << std::endl;
    return 0;
}