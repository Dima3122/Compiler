#include "Node.hpp"

Node::Node(std::string name, std::string type, int size, int level, int line)
{
    this->name = name;
    this->type = type;
    this->size = size;
    this->level = level;
    this->line = line;
}

int Node::GetHash(std::string Name)
{
    uint seed = 131313;
    int hash = 0;
    for (int i = 0; i < Name.size(); i++)
    {
        hash = (int)(((hash * seed) << 2) + Name[i] + i);
    }
    return hash % 100000;
}

void Node::print()
{
    std::cout << "  name=" << name << ", type=" << type << ", size=" << size << ", level=" << level << ", line_number=" << line << std::endl;
}