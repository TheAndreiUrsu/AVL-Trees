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
	AVL_Node() { this->value = "NAME"; this->key = "0000000000"; this->left = nullptr; this->right = nullptr; }; // default constructor

	AVL_Node(std::string key) { this->key = key; this->left = nullptr; this->right = nullptr; }; // paramaterized constructor

	~AVL_Node() { // destructor
		if (this->left != nullptr)
			delete this->left;
		if (this->right != nullptr)
			delete this->right;
		std::cout << "Node destroyed!" << std::endl; 
	}

	// Getters and Setters.
	void setLeft(AVL_Node* left) { this->left = left; };
	AVL_Node* getLeft() { return this->left; };

	void setRight(AVL_Node* right) { this->right = right; };
	AVL_Node* getRight() { return this->right; };

	void setValue(std::string value) { this->value = value; };
	std::string getValue() { return this->value; };

	void setKey(std::string key) { this->key = key; };
	std::string getKey() { return this->key; };

	void setBalanceFactor(int bf) { this->balance_factor = bf; };
	int getBalanceFactor() { return this->balance_factor; };
};

class AVL_Tree {
private:
	AVL_Node* root; // An AVL_Tree has a root
public:
	
	// Constructors and Destructors
	AVL_Tree() { std::cout << "Tree created!" << std::endl; };
	~AVL_Tree() { 
		if (root != nullptr) {
			delete root;
		}
		std::cout << "Tree destroyed!" << std::endl; 
	};

	// Inserts a node using recursion. 
	AVL_Node* insertNode(std::string val, std::string key, AVL_Node* root = nullptr) {
		if (root == nullptr) {
			root = new AVL_Node(key);
			root->setValue(val);
			root->setBalanceFactor(0);
			this->root = root;
			return root;
		}

		if (std::stoi(key) > std::stoi(root->getKey())) {
			root->setRight(insertNode(val, key, root->getRight()));
		}
		else if (std::stoi(key) < std::stoi(root->getKey())) {
			root->setLeft(insertNode(val, key, root->getLeft()));
		}
		return root;
	}

	// Debugging to print out the tree.
	int printTree() {
		std::queue<AVL_Node*> q;
		int count = 0;
		if (this->root != nullptr) {
			q.push(this->root);

			while (!q.empty()) {
				AVL_Node* curr = q.front();
				q.pop();
				std::cout << "Node " << count << ": " << curr->getValue() << ", key: " << curr->getKey() << ", BF: " << curr->getBalanceFactor() << std::endl;

				if (curr->getLeft() != nullptr)
					q.push(curr->getLeft());
				if (curr->getRight() != nullptr)
					q.push(curr->getRight());
				count++;
			}
			
			
			return 0;
		}
		return -1;
	}

};