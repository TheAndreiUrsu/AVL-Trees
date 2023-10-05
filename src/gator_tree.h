#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "gator_node.h"

class Gator_Tree {
private:
    // Primary data members
    Gator_Node* root;
    std::vector<Gator_Node*> gator_vect;

    // Vectors for tree traversal
    std::vector<std::string> in_order;
    std::vector<int> in_order_ID;
    std::vector<std::string> post_order;
    std::vector<std::string> pre_order;

    int levels; // Number of levels in the tree

    // Helper functions for tree traversal and height calculation
    void inOrderHelper(Gator_Node* root_);
    void postOrderHelper(Gator_Node* root_);
    void preOrderHelper(Gator_Node* root_);
    void treeHelper(Gator_Node* root_);
    int heightHelper(Gator_Node* root_);

    // Helper functions for inserting and deleting nodes
    Gator_Node* insertNodeHelper(Gator_Node* root_, std::string name, std::string ID);
    Gator_Node* deleteNodeHelper(Gator_Node* root_, std::string ID);

    // Utility functions for data verification
    std::string verifyID(std::string& number);
    std::string verifyName(std::string& word);

public:
	/*===== Constructor/Destructor =====*/
    Gator_Tree();
	~Gator_Tree()= default;

	/*===== Insertions =====*/
	std::string insertNode(std::string name, std::string ID);

    /*===== Deletions =====*/
    std::string deleteNode(std::string ID);
    std::string deleteNodeInorder(int N);

    /*===== Searching =====*/
    std::string searchNodeByKey(std::string ID);
    std::string searchNodeByValue(std::string name);

	/*===== DFS Traversals =====*/
	std::vector<std::string> inOrder();
	std::vector<std::string> postOrder();
	std::vector<std::string> preOrder();

	/*===== Tree Height =====*/
	int treeHeight();

    int getLevelCount();

	/*===== Rotations =====*/
    Gator_Node* rightRotate(Gator_Node* root_);
    Gator_Node* leftRotate(Gator_Node* root_);

    Gator_Node* changeBalanceAndHeight(Gator_Node* root_);

	/*===== Debugging =====*/
	std::vector<Gator_Node*> getTree();
};