#include "avl_tree_node.h"

bool AVL_Node::operator>(const AVL_Node* rhs) {
	return this->key > rhs->key;
}