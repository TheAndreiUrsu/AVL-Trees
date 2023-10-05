#include "gator_tree.h"

Gator_Node::Gator_Node(std::string name, std::string ID) {
	this->name = name;
    this->ID = ID;
    this->left_node = nullptr;
    this->right_node = nullptr;
	this->height = 0;
	this->balance_factor = 0;
}
