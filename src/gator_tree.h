#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "gator_node.h"

class Gator_Tree {
private:
    Gator_Node* root;

    Gator_Node* insertNodeHelper(Gator_Node* root, std::string name, int ID);

	std::vector<int> in_order;
	std::vector<int> post_order;
	std::vector<int> pre_order;

	std::vector<Gator_Node*> gator_vect;

	void inOrderHelper(Gator_Node* root_);
	void postOrderHelper(Gator_Node* root_);
	void preOrderHelper(Gator_Node* root_);

	void treeHelper(Gator_Node* root_);

	int right_node(Gator_Node* root_);

public:
	/*===== Constructor/Destructor =====*/
    Gator_Tree();
	~Gator_Tree();

	/*===== Insertions =====*/
	void insertNode(std::string name, int ID);

	/*===== DFS Traversals =====*/
	std::vector<int> inOrder();
	std::vector<int> postOrder();
	std::vector<int> preOrder();

	/*===== Tree Height =====*/
	int treeHeight();

	/*===== Rotations =====*/
    Gator_Node* rightRotate(Gator_Node* root_);
    Gator_Node* leftRotate(Gator_Node* root_);

    Gator_Node* changeBalanceAndHeight(Gator_Node* root_);

	/*===== Debugging =====*/
	void printHeightAndBalanceFactor();
	std::vector<Gator_Node*> getTree();
    Gator_Node* getRoot(){return this->root;};
};