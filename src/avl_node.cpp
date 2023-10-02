#include "avl_tree_node.h"

AVL_Node::AVL_Node(int key) {
	this->key = key;
	this->left = nullptr;
	this->right = nullptr;
	this->height = 0;
	this->balance_factor = 0;
}
