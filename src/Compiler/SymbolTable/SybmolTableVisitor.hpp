#pragma once
#include <iostream>
#include <CSharpGrammarBaseVisitor.h>
#include "Node.hpp"

class SybmolTableVisitor: public CSharpGrammarBaseVisitor
{
private:
    std::map<int, Node> SybmolTable;
public:
    SybmolTableVisitor();
    ~SybmolTableVisitor();
};