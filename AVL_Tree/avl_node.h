#pragma once
class AVL_Node {
public:
    friend class AVL_Tree;
private:
    int key;
    int balance_factor; // Height of left subtree - height of right subtree
    int height;

    AVL_Node* left;
    AVL_Node* right;

    AVL_Node() {};
    AVL_Node(int key);
};