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
	if (root == nullptr) {
		return new_node;
	}
		
	// Check if it is less than, to go to left subtree, else go to right subtree.
	if (new_node->key < root->key)
		root->left = insertNodeHelper(root->left, key);
	else
		root->right = insertNodeHelper(root->right, key);

	// Update height of node
	root->height = std::max(treeHeightHelper(root->left), treeHeightHelper(root->right));

	root->balance_factor = treeHeightHelper(root->left) - treeHeightHelper(root->right);

	// Right heavy
	if (root->balance_factor < -1 && key > root->right->key) {
		AVL_Node* right_subtree = root->right;
		if (right_subtree->balance_factor > 1 && key < right_subtree->left->key) {
			right_subtree = rightRotate(right_subtree);
			return leftRotate(root);
		}
		else
			return leftRotate(root);
	}
	// Left heavy
	if (root->balance_factor > 1 && key < root->left->key) {
		AVL_Node* left_subtree = root->left;
		if (left_subtree->balance_factor < -1 && key > left_subtree->right->key) {
			left_subtree = leftRotate(left_subtree);
			return rightRotate(root);
		}
		else
			return rightRotate(root);
		
	}

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

AVL_Node* AVL_Tree::rightRotate(AVL_Node* root) {
	std::cout << "Rotating Right!" << std::endl;
	
	AVL_Node* child = root->left;
	AVL_Node* right_child_of_child = child->right; // could be null or exists

	child->left = root;
	root->right = right_child_of_child;

	// Updating heights and balance factors of child.
	child->height = std::max(treeHeightHelper(child->left), treeHeightHelper(child->right));
	child->balance_factor = treeHeightHelper(child->left) - treeHeightHelper(child->right);

	// Return the new root of the rotated subtree.
	return child;
}
AVL_Node* AVL_Tree::leftRotate(AVL_Node* root) {
	std::cout << "Rotating Left!" << std::endl;
	
	AVL_Node* child = root->right;
	AVL_Node* left_child_of_child = child->left; // could be null or exists

	child->left = root;
	root->right = left_child_of_child;

	// Updating heights and balance factors of root and child.
	child->height = std::max(treeHeightHelper(child->left), treeHeightHelper(child->right));
	child->balance_factor = treeHeightHelper(child->left) - treeHeightHelper(child->right);

	// Return the new root of the rotated subtree.
	return child;
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
	
	if (root == nullptr)
		return 0;
	else {
		//std::cout << "Root: " << root->key << std::endl;
		return 1 + std::max((root->left ? treeHeightHelper(root->left) : 0), (root->right ? treeHeightHelper(root->right) : 0));
	}
	
}
int AVL_Tree::treeHeight()
{
	return treeHeightHelper(this->root);
}


/*===== Debugging =====*/
std::vector<AVL_Node*> AVL_Tree::getTree() {
	if (this->tree_vect.size() > 0) {
		return this->tree_vect;
	}

	this->treeHelper(this->root);
	return this->tree_vect;
}
void AVL_Tree::treeHelper(AVL_Node* root) {
	if (root != nullptr) {
		treeHelper(root->left);
		this->tree_vect.push_back(root);
		treeHelper(root->right);
	}
}


void AVL_Tree::printHeightAndBalanceFactor() {
	for (int i = 0; i < this->tree_vect.size(); ++i) {
		std::cout << "Node " << tree_vect[i]->key << ", Height: " << tree_vect[i]->height << ", BF: " << tree_vect[i]->balance_factor << std::endl;
	}
}