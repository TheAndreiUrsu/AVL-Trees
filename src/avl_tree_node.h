#pragma once
#include <iostream>
#include <string>
#include <vector>

class AVL_Node {
public:
	friend class AVL_Tree;
private:
	int key;
	int balance_factor; // Height of left subtree - height of right subtree
	int height;

	bool is_leaf;

	AVL_Node* left;
	AVL_Node* right;

	AVL_Node() {};
	AVL_Node(int key);
};

class AVL_Tree {
private:
	AVL_Node* root;

	AVL_Node* insertNodeHelper(AVL_Node* root, int key);

	std::vector<int> in_order;
	std::vector<int> post_order;
	std::vector<int> pre_order;

	std::vector<AVL_Node*> tree_vect;

	void inOrderHelper(AVL_Node* root);
	void postOrderHelper(AVL_Node* root);
	void preOrderHelper(AVL_Node* root);

	void treeHelper(AVL_Node* root);

	int treeHeightHelper(AVL_Node* root);

public:
	/*===== Constructor/Destructor =====*/
	AVL_Tree();
	~AVL_Tree();

	/*===== Insertions =====*/
	void insertNode(int key);

	/*===== DFS Traversals =====*/
	std::vector<int> inOrder();
	std::vector<int> postOrder();
	std::vector<int> preOrder();

	/*===== Tree Height =====*/
	int treeHeight();

	/*===== Rotations =====*/
	AVL_Node* rightRotate(AVL_Node* root);
	AVL_Node* leftRotate(AVL_Node* root);

	/*===== Debugging =====*/
	void printHeightAndBalanceFactor();
	std::vector<AVL_Node*> getTree();
};