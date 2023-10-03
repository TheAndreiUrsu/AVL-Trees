#include "avl_tree.h"

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
	if(root->balance_factor < -1){
        std::cout << "Tree is right heavy!" << std::endl;
        if(key < root->right->key){
            std::cout << "Subtree is left heavy!" << std::endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        else{
            std::cout << "Subtree is right heavy!" << std::endl;
            return leftRotate(root);
        }
    }
    else if(root->balance_factor > 1){
        std::cout << "Tree is left heavy!" << std::endl;
        if(key > root->left->key){
            std::cout << "Subtree is right heavy!" << std::endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else{
            std::cout << "Subtree is left heavy!" << std::endl;
            return rightRotate(root);
        }
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

AVL_Node* AVL_Tree::rightRotate(AVL_Node* Gator_Node) {
	std::cout << "Rotating right!" << std::endl;

    AVL_Node* child = Gator_Node->left;
    Gator_Node->left = child->right;
    child->right = Gator_Node;

    // Return the new Gator_Node of the rotated subtree.
    return changeBalanceAndHeight(child);
}

AVL_Node* AVL_Tree::leftRotate(AVL_Node* root) {
	std::cout << "Rotating Left!" << std::endl;

    AVL_Node* child = root->right;
    root->right = child->left;
    child->left = root;

    // Return the new root of the rotated subtree.
	return changeBalanceAndHeight(child);
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



int AVL_Tree::treeHeightHelper(AVL_Node* avl_root) {
	
	if (avl_root == nullptr)
		return 0;
	else {
		return 1 + std::max((avl_root->left ? treeHeightHelper(avl_root->left) : 0), (avl_root->right ? treeHeightHelper(avl_root->right) : 0));
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
void AVL_Tree::treeHelper(AVL_Node* avl_root) {
	if (avl_root != nullptr) {
		treeHelper(avl_root->left);
		this->tree_vect.push_back(avl_root);
		treeHelper(avl_root->right);
	}
}


void AVL_Tree::printHeightAndBalanceFactor() {
	std::queue<AVL_Node*> q;
    int level = 0;
    q.push(this->root);

    while(!q.empty()){
        int size = q.size();
        std::cout << "Level: " << level << std::endl;
        for(int i = 0; i < size; ++i){
            AVL_Node* curr = q.front();
            q.pop();
            std::cout << "Node " << curr->key << ", Height: " << curr->height << ", BF: " << curr->balance_factor << std::endl;

            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
        level++;
    }

    std::cout << "Levels: " << level << std::endl;

}

AVL_Node* AVL_Tree::changeBalanceAndHeight(AVL_Node* root) {
    if(root != nullptr){
        root->height = std::max(treeHeightHelper(root->left), treeHeightHelper(root->right));
        root->balance_factor = treeHeightHelper(root->left) - treeHeightHelper(root->right);
    }
    if(root->left != nullptr){
        root->left->height = std::max(treeHeightHelper(root->left->left), treeHeightHelper(root->left->right));
        root->left->balance_factor = treeHeightHelper(root->left->left) - treeHeightHelper(root->left->right);
    }
    if(root->right != nullptr){
        root->right->height = std::max(treeHeightHelper(root->right->left), treeHeightHelper(root->right->right));
        root->right->balance_factor = treeHeightHelper(root->right->left) - treeHeightHelper(root->right->right);
    }

    return root;
}


