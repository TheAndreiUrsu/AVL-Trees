#include "avl_tree_node.h"

void AVL_Tree::insertNode(std::string val, int key) {
	
	AVL_Node* new_node = new AVL_Node(key);
	
	// Empty Tree, add root.
	if (this->root == nullptr) {
		this->root = new_node;
		this->root->setValue(val);
		this->root->setBalanceFactor(0);
		this->tree.push_back(this->root);
		return;
	}
	
	// All other cases.
	AVL_Node* dummy = nullptr;
	AVL_Node* curr = this->root;
	while (curr != nullptr) {
		if (curr > new_node) {
			dummy = curr;
			curr = curr->left;
		}
		else if (curr < new_node) {
			dummy = curr;
			curr = curr->right;
		}
	}

	new_node->setValue(val);
	if (dummy > new_node) {
		dummy->left = new_node;
		this->tree.push_back(new_node);
	}
	else if (dummy < new_node) {
		dummy->right = new_node;
		this->tree.push_back(new_node);
	}

}

void AVL_Tree::printTree() {
	for (unsigned int i = 1; i < this->tree.size(); ++i) {
		std::cout << "Node, key: " << this->tree.at(i)->getKey() << ", value: " << this->tree.at(i)->getValue() << std::endl;
	}
}