#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

struct LevelFunc
{
    std::vector<int> FriendLevel;    
};

class Node
{
private:
    std::string text, name, type;
    int line, level;
    //std::map<int, LevelFunc> level;
public:
    Node() = default;
    Node(std::string text, std::string name, std::string type, int level, int line);
    ~Node() = default;

    void print();
    static int GetHash(std::string Name);
};