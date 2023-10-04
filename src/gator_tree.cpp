#include "gator_tree.h"

Gator_Tree::Gator_Tree() {
	this->root = nullptr;
    this->levels = 0;
	//std::cout << "Tree created!" << std::endl;
}
Gator_Tree::~Gator_Tree() { /*std::cout << "Tree destroyed!" << std::endl;*/ }

/*===== Insertion =====*/
Gator_Node* Gator_Tree::insertNodeHelper(Gator_Node* root_, const std::string& name, int ID) {
    Gator_Node* new_node = new Gator_Node(name, ID);

	// Empty tree, add root.
	if (root_ == nullptr) {
		return new_node;
	}
		
	// Check if it is less than, to go to left subtree, else go to right subtree.
	if (new_node->ID < root_->ID)
        root_->left_node = insertNodeHelper(root_->left_node, name, ID);
	else
        root_->right_node = insertNodeHelper(root_->right_node, name, ID);

	// Update height of node
    root_->height = std::max(heightHelper(root_->left_node), heightHelper(root_->right_node));

    root_->balance_factor = heightHelper(root_->left_node) - heightHelper(root_->right_node);

	// Right heavy
	if(root_->balance_factor < -1){
        std::cout << "Tree is right heavy!" << std::endl;
        if(ID < root_->right_node->ID){
            std::cout << "Subtree is left heavy!" << std::endl;
            root_->right_node = rightRotate(root_->right_node);
            return leftRotate(root_);
        }
        else{
            std::cout << "Subtree is right heavy!" << std::endl;
            return leftRotate(root_);
        }
    }
    else if(root_->balance_factor > 1){
        std::cout << "Tree is left heavy!" << std::endl;
        if(ID > root_->left_node->ID){
            std::cout << "Subtree is right heavy!" << std::endl;
            root_->left_node = leftRotate(root_->left_node);
            return rightRotate(root_);
        }
        else{
            std::cout << "Subtree is left heavy!" << std::endl;
            return rightRotate(root_);
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

	return root_;
}
void Gator_Tree::insertNode(std::string name, int ID) {
	this->root = insertNodeHelper(this->root, name, ID);
}

Gator_Node* Gator_Tree::rightRotate(Gator_Node* root_) {
	std::cout << "Rotating right!" << std::endl;

    Gator_Node* child = root_->left_node;
    root_->left_node = child->right_node;
    child->right_node = root_;

    // Return the new Gator_Node of the rotated subtree.
    return changeBalanceAndHeight(child);
}

Gator_Node* Gator_Tree::leftRotate(Gator_Node* root_) {
	std::cout << "Rotating Left!" << std::endl;

    Gator_Node* child = root_->right_node;
    root_->right_node = child->left_node;
    child->left_node = root_;

    // Return the new root of the rotated subtree.
	return changeBalanceAndHeight(child);
}

/*===== DFS Traversals =====*/
void Gator_Tree::inOrderHelper(Gator_Node* root_) {

	if (root_ != nullptr) {
		inOrderHelper(root_->left_node);
		this->in_order.push_back(root_->name);
		inOrderHelper(root_->right_node);
	}

}
std::vector<std::string> Gator_Tree::inOrder() {
	if (this->in_order.size() > 0) {
		return this->in_order;
	}

	this->inOrderHelper(this->root);
	return this->in_order;
}

void Gator_Tree::postOrderHelper(Gator_Node* root_)
{
	if (root_ != nullptr) {
		postOrderHelper(root_->left_node);
		postOrderHelper(root_->right_node);
		this->post_order.push_back(root_->name);
	}
}
std::vector<std::string> Gator_Tree::postOrder()
{
	if (this->post_order.size() > 0) {
		return this->post_order;
	}

	this->postOrderHelper(this->root);
	return this->post_order;
}

void Gator_Tree::preOrderHelper(Gator_Node* root_)
{
	if (root_ != nullptr) {
		this->pre_order.push_back(root_->name);
		preOrderHelper(root_->left_node);
		preOrderHelper(root_->right_node);
	}
}
std::vector<std::string> Gator_Tree::preOrder()
{
	if (!this->pre_order.empty()) {
		return this->pre_order;
	}
	
	this->preOrderHelper(this->root);
	return this->pre_order;
}



int Gator_Tree::heightHelper(Gator_Node* root_) {
	
	if (root_ == nullptr)
		return 0;
	else {
		return 1 + std::max((root_->left_node ? heightHelper(root_->left_node) : 0), (root_->right_node ? heightHelper(root_->right_node) : 0));
	}
	
}
int Gator_Tree::treeHeight()
{
	return heightHelper(this->root);
}


/*===== Debugging =====*/
std::vector<Gator_Node*> Gator_Tree::getTree() {
	if (!this->gator_vect.empty()) {
		return this->gator_vect;
	}

	this->treeHelper(this->root);
	return this->gator_vect;
}
void Gator_Tree::treeHelper(Gator_Node* avl_root) {
	if (avl_root != nullptr) {
		treeHelper(avl_root->left_node);
		this->gator_vect.push_back(avl_root);
		treeHelper(avl_root->right_node);
	}
}

int Gator_Tree::getLevelCount() {
    if(this->root == nullptr)
        return 0;

    std::queue<Gator_Node*> q;
    int level = 0;
    q.push(this->root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            Gator_Node* curr = q.front();
            q.pop();

            if(curr->left_node != nullptr)
                q.push(curr->left_node);
            if(curr->right_node != nullptr)
                q.push(curr->right_node);
        }
        level++;
    }

    return level;
}

void Gator_Tree::printHeightAndBalanceFactor() {
	std::queue<Gator_Node*> q;
    int level = 0;
    q.push(this->root);

    while(!q.empty()){
        int size = q.size();
        std::cout << "Level: " << level << std::endl;
        for(int i = 0; i < size; ++i){
            Gator_Node* curr = q.front();
            q.pop();
            std::cout << "Node " << curr->ID << ", Height: " << curr->height << ", BF: " << curr->balance_factor << std::endl;

            if(curr->left_node != nullptr)
                q.push(curr->left_node);
            if(curr->right_node != nullptr)
                q.push(curr->right_node);
        }
        level++;
    }

    std::cout << "Levels: " << level << std::endl;

}

Gator_Node* Gator_Tree::changeBalanceAndHeight(Gator_Node* root_) {
    if(root_ != nullptr){
        root_->height = std::max(heightHelper(root_->left_node), heightHelper(root_->right_node));
        root_->balance_factor = heightHelper(root_->left_node) - heightHelper(root_->right_node);
    }
    if(root_->left_node != nullptr){
        root_->left_node->height = std::max(heightHelper(root_->left_node->left_node), heightHelper(root_->left_node->right_node));
        root_->left_node->balance_factor = heightHelper(root_->left_node->left_node) - heightHelper(root_->left_node->right_node);
    }
    if(root_->right_node != nullptr){
        root_->right_node->height = std::max(heightHelper(root_->right_node->left_node), heightHelper(root_->right_node->right_node));
        root_->right_node->balance_factor = heightHelper(root_->right_node->left_node) - heightHelper(root_->right_node->right_node);
    }

    return root_;
}

void Gator_Tree::deleteNode(int ID) {

}

std::string Gator_Tree::searchNodeByKey(int ID) {
    if(ID == this->root->ID)
        return this->root->name + "\n";

    std::vector<Gator_Node*> nodes = this->getTree();

    for(auto & node : nodes){
        if(node->ID == ID){
            return node->name + "\n";
        }
    }

    return "unsuccessful\n";
}

std::string Gator_Tree::searchNodeByValue(const std::string& name){
    if(name == this->root->name)
        return std::to_string(this->root->ID) + "\n";

    std::vector<Gator_Node*> nodes = this->getTree();
    std::vector<int> ID;
    std::string s;

    for(auto & node : nodes){
        if(node->name == name){
            ID.push_back(node->ID);
        }
    }
    if(!ID.empty()){
        if(ID.size() < 2){
            return std::to_string(ID[0]) + "\n";
        }

        for(auto& num : ID){
            s += std::to_string(num) + " ";
        }
        return s + "\n";
    }

    return "unsuccessful\n";
}


