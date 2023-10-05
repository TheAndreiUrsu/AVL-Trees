#pragma once
#include <string>
class Gator_Node {
public:
    friend class Gator_Tree;
private:
    std::string name;
    std::string ID;
    int balance_factor; // Height of left subtree - height of right subtree
    int height;

    Gator_Node* left_node;
    Gator_Node* right_node;

    //Gator_Node() {};
    Gator_Node(std::string name, std::string ID);
};