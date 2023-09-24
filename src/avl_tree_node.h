#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <vector>

class AVL_Node {
public:
	friend class AVL_Tree;

private:
	// a node has a value and a key
	std::string value;
	int key;

	int balance_factor; // between -2 and +2.
	
	// Pointers to the children nodes.
	AVL_Node* left;
	AVL_Node* right;

	AVL_Node() { this->value = ""; this->key = 0000000000; this->left = nullptr; this->right = nullptr; }; // default constructor

	AVL_Node(int key) { this->key = key; this->left = nullptr; this->right = nullptr; }; // paramaterized constructor

	~AVL_Node();

	/*==== Operators ====*/
	bool operator>(const AVL_Node* rhs);

	// Getters and Setters.
	void setLeft(AVL_Node* left) { this->left = left; };
	AVL_Node* getLeft() { return this->left; };

	void setRight(AVL_Node* right) { this->right = right; };
	AVL_Node* getRight() { return this->right; };

	void setValue(std::string value) { this->value = value; };
	std::string getValue() { return this->value; };

	void setKey(int key) { this->key = key; };
	int getKey() { return this->key; };

	void setBalanceFactor(int bf) { this->balance_factor = bf; };
	int getBalanceFactor() { return this->balance_factor; };
};

class AVL_Tree {
private:
	AVL_Node* root; // An AVL_Tree has a root
	std::vector<AVL_Node*> tree;

public:
	
	// Constructors and Destructors
	AVL_Tree() { this->root = nullptr;  this->tree.push_back(this->root); std::cout << "Tree created!" << std::endl; };
	~AVL_Tree() { std::cout << "Tree destroyed!" << std::endl; };

	// Inserts a node using recursion. 
	void insertNode(std::string val, int key);

	// Debugging to print out the tree.
	void printTree();

};