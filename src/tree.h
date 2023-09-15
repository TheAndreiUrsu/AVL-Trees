#pragma once
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
};

class AVL_Tree {

public:
	AVL_Tree() { std::cout << "Tree created!"; };
	~AVL_Tree() { std::cout << "Tree destroyed!"; };
};