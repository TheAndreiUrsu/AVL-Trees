#pragma once
#include <iostream>
#include <string>

class AVL_Node {
public:
	friend class AVL_Tree;
private:
	int key;
	int balance_factor;

	AVL_Node* left;
	AVL_Node* right;

	AVL_Node() { this->key = 0; };
	AVL_Node(int key);
};

class AVL_Tree {
private:
	AVL_Node* root;

	AVL_Node* insertNodeHelper(AVL_Node* root, int key);
	void inOrderHelper(AVL_Node* root);

public:
	/*===== Constructor/Destructor =====*/
	AVL_Tree();
	~AVL_Tree();

	/*===== Insertions =====*/
	void insertNode(int key);

	/*===== DFS Traversals =====*/
	void inOrder();

};