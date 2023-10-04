#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "gator_node.h"

class Gator_Tree {
private:
    Gator_Node* root;

    Gator_Node* insertNodeHelper(Gator_Node* root, const std::string& name, int ID);

	std::vector<std::string> in_order;
	std::vector<std::string> post_order;
	std::vector<std::string> pre_order;

	std::vector<Gator_Node*> gator_vect;

    int levels;

	void inOrderHelper(Gator_Node* root_);
	void postOrderHelper(Gator_Node* root_);
	void preOrderHelper(Gator_Node* root_);

	void treeHelper(Gator_Node* root_);

	int heightHelper(Gator_Node* root_);

public:
	/*===== Constructor/Destructor =====*/
    Gator_Tree();
	~Gator_Tree();

	/*===== Insertions =====*/
	void insertNode(std::string name, int ID);

    /*===== Deletions =====*/
    void deleteNode(int ID);

    /*===== Searching =====*/
    std::string searchNodeByKey(int ID);
    std::string searchNodeByValue(const std::string& name);

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
	void printHeightAndBalanceFactor();
	std::vector<Gator_Node*> getTree();
    Gator_Node* getRoot(){return this->root;};
};