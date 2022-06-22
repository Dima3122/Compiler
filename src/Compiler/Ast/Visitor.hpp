#pragma once
#include "Ast.hpp"
#include <iostream>
#include <any>

class Program;

class Visitor
{

public:
    Visitor() = default;
    ~Visitor() = default;
    virtual std::any visit(Program &value) = 0;
};