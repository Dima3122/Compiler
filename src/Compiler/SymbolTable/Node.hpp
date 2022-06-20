#include <iostream>
#include <string>

class Node
{
private:
    std::string name, type;
    int size, level, line;
    //Node *next;    
public:
    Node() = default;
    Node(std::string name, std::string type, int size, int level, int line);
    ~Node() = default;

    void print();
    static int GetHash(std::string Name);
};