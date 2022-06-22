#include "Ast.hpp"

void Program::add_expression(Expression *expression)
{
    expressions_.emplace_back(expression);
}

void Program::set_expressions(std::vector<ExpressionPtr> expressions)
{
    expressions_ = std::move(expressions);
}

void Program::accept(Visitor &visitor)
{
    visitor.visit(*this);
}