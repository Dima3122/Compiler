#pragma once
#include <vector>
#include <memory>
#include "Visitor.hpp"

class Expression;
class Visitor;

class Program final
{
public:
    using ExpressionPtr = std::shared_ptr<Expression>;

    void add_expression(Expression *expression);
    void set_expressions(std::vector<ExpressionPtr> expressions);

    std::vector<ExpressionPtr> get_expressions() { return expressions_; }
    void accept(Visitor &visitor);

private:
    std::vector<ExpressionPtr> expressions_;
};

class Expression
{
public:
    virtual ~Expression() = default;
    virtual void accept(Visitor &visitor) = 0;
};