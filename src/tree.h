#pragma once
#include <iostream>
#include <string>
#include <queue>

class AVL_Node {
private:
	std::string value, key; // a node has a value and a key

	int balance_factor; // between -2 and +2.
	
	// Pointers to the children nodes.
	AVL_Node* left;
	AVL_Node* right;

public:
	AVL_Node() { this->value = "NAME"; this->key = "0000000000"; }; // default constructor

	AVL_Node(std::string val, std::string key) { this->value = val; this->key = key; }; // paramaterized constructor

	~AVL_Node() { // destructor
		if (this->left != nullptr)
			delete this->left;
		if (this->right != nullptr)
			delete this->right;
		std::cout << "Node destroyed!"; 
	}

	// Getters and Setters.
	AVL_Node* setLeft(AVL_Node* left) { this->left = left; };
	AVL_Node* getLeft() { return this->left; };

	AVL_Node* setRight(AVL_Node* right) { this->right = right; };
	AVL_Node* getRight() { return this->right; };

	void setValue(int value) { this->value = value; };
	std::string getValue() { return this->value; };

	void setKey(int key) { this->key = key; };
	std::string getKey() { return this->key; };

	void setBalanceFactor(int bf) { this->balance_factor = bf; };
	int getBalanceFactor() { return this->balance_factor; };
};

class AVL_Tree {
private:
	AVL_Node* root; // An AVL_Tree has a root
public:
	
	// Constructors and Destructors
	AVL_Tree() { std::cout << "Tree created!"; };
	~AVL_Tree() { 
		if (root != nullptr) {
			delete root;
		}
		std::cout << "Tree destroyed!"; 
	};

};