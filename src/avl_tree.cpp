#include "avl_tree_node.h"

AVL_Tree::AVL_Tree() { 
	this->root = nullptr;
	std::cout << "Tree created!" << std::endl; 
}
AVL_Tree::~AVL_Tree() { std::cout << "Tree destroyed!" << std::endl; }

/*===== Insertion =====*/
AVL_Node* AVL_Tree::insertNodeHelper(AVL_Node* root, int key) {
	AVL_Node* new_node = new AVL_Node(key);

	// Empty tree, add root.
	if (root == nullptr)
		return new_node;

	// Check if it is less than, to go to left subtree, else go to right subtree.
	if (new_node < root)
		root->left = insertNodeHelper(root->left, key);
	else
		root->right = insertNodeHelper(root->right, key);

	return root;
}
void AVL_Tree::insertNode(int key) {
	this->root = insertNodeHelper(this->root, key);
}

/*===== DFS Traversals =====*/
void AVL_Tree::inOrderHelper(AVL_Node* root) {
	if (root == nullptr) {
		std::cout << "";
	}
	else {
		inOrderHelper(root->left);
		std::cout << root->key << " ";
		inOrderHelper(root->right);
	}
}
void AVL_Tree::inOrder() {
	this->inOrderHelper(this->root);
}