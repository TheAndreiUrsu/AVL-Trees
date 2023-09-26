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
	if (new_node->key < root->key)
		root->left = insertNodeHelper(root->left, key);
	else
		root->right = insertNodeHelper(root->right, key);

	/*
		IF tree is right heavy
			IF tree's right subtree is left heavy
				Perform Right Left Rotation
			ELSE
				Perform Left rotation
		ELSE IF tree is left heavy
			IF tree's left subtree is right heavy
				Perform Left Right rotation
			ELSE
				Perform Right rotation
	*/

	return root;
}
void AVL_Tree::insertNode(int key) {
	this->root = insertNodeHelper(this->root, key);
}

/*===== DFS Traversals =====*/
void AVL_Tree::inOrderHelper(AVL_Node* root) {

	if (root != nullptr) {
		inOrderHelper(root->left);
		this->in_order.push_back(root->key);
		inOrderHelper(root->right);
	}

}
std::vector<int> AVL_Tree::inOrder() {
	if (this->in_order.size() > 0) {
		return this->in_order;
	}

	this->inOrderHelper(this->root);
	return this->in_order;
}

void AVL_Tree::postOrderHelper(AVL_Node* root)
{
	if (root != nullptr) {
		postOrderHelper(root->left);
		postOrderHelper(root->right);
		this->post_order.push_back(root->key);
	}
}
std::vector<int> AVL_Tree::postOrder()
{
	if (this->post_order.size() > 0) {
		return this->post_order;
	}

	this->postOrderHelper(this->root);
	return this->post_order;
}

void AVL_Tree::preOrderHelper(AVL_Node* root)
{
	if (root != nullptr) {
		this->pre_order.push_back(root->key);
		preOrderHelper(root->left);
		preOrderHelper(root->right);
	}
}
std::vector<int> AVL_Tree::preOrder()
{
	if (this->pre_order.size() > 0) {
		return this->pre_order;
	}
	
	this->preOrderHelper(this->root);
	return this->pre_order;
}



int AVL_Tree::treeHeightHelper(AVL_Node* root) {
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	else {
		if (root->left != nullptr) {
			return 1 + treeHeightHelper(root->left);
		}
		if (root->right != nullptr) {
			return 1 + treeHeightHelper(root->right);
		}
	}
}
int AVL_Tree::treeHeight()
{
	return treeHeightHelper(this->root);
}
