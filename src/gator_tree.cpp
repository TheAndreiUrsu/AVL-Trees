#include "gator_tree.h"

Gator_Tree::Gator_Tree() {
	this->root = nullptr;
    this->levels = 0;
}

/*===== Insertion =====*/
Gator_Node* Gator_Tree::insertNodeHelper(Gator_Node* root_, std::string name, std::string ID) {
    Gator_Node* new_node = new Gator_Node(name, ID);

	// Empty tree, add root.
	if (root_ == nullptr) {
        this->outputs.emplace_back("successful\n");
		return new_node;
	}

    if(new_node->ID == root_->ID){
        this->outputs.emplace_back("unsuccessful\n");
        return nullptr;
    }
		
	// Check if it is less than, to go to left subtree, else go to right subtree.s
	if (new_node->ID < root_->ID)
        root_->left_node = insertNodeHelper(root_->left_node, name, ID);
	else
        root_->right_node = insertNodeHelper(root_->right_node, name, ID);

	// Update height of node
    root_->height = std::max(heightHelper(root_->left_node), heightHelper(root_->right_node));

    root_->balance_factor = heightHelper(root_->left_node) - heightHelper(root_->right_node);

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

	// Right heavy
	if(root_->balance_factor < -1){
        if(ID < root_->right_node->ID){
            root_->right_node = rightRotate(root_->right_node);
            return leftRotate(root_);
        }
        else{
            return leftRotate(root_);
        }
    }
    else if(root_->balance_factor > 1){
        if(ID > root_->left_node->ID){
            root_->left_node = leftRotate(root_->left_node);
            return rightRotate(root_);
        }
        else{
            return rightRotate(root_);
        }
    }

	return root_;
}
void Gator_Tree::insertNode(std::string name, std::string ID) {
    name = this->verifyName(name);
    ID = this->verifyID(ID);

    if(!name.empty() && !ID.empty()){
        this->root = insertNodeHelper(this->root, name, ID);
    }
    else{
        outputs.emplace_back("unsuccessful\n");
    }
}

Gator_Node* Gator_Tree::rightRotate(Gator_Node* root_) {

    Gator_Node* child = root_->left_node;
    root_->left_node = child->right_node;
    child->right_node = root_;

    // Return the new Gator_Node of the rotated subtree.
    return changeBalanceAndHeight(child);
}

Gator_Node* Gator_Tree::leftRotate(Gator_Node* root_) {
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
	this->in_order.clear();
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
    this->post_order.clear();
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
    this->pre_order.clear();
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
    this->gator_vect.clear();
	this->treeHelper(this->root);
	return this->gator_vect;
}
// in order representation of tree
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

Gator_Node* Gator_Tree::changeBalanceAndHeight(Gator_Node* root_) {
    if(root_ != nullptr){
        root_->height = std::max(heightHelper(root_->left_node), heightHelper(root_->right_node));
        root_->balance_factor = heightHelper(root_->left_node) - heightHelper(root_->right_node);

        if(root_->left_node != nullptr){
            root_->left_node->height = std::max(heightHelper(root_->left_node->left_node), heightHelper(root_->left_node->right_node));
            root_->left_node->balance_factor = heightHelper(root_->left_node->left_node) - heightHelper(root_->left_node->right_node);
        }
        if(root_->right_node != nullptr){
            root_->right_node->height = std::max(heightHelper(root_->right_node->left_node), heightHelper(root_->right_node->right_node));
            root_->right_node->balance_factor = heightHelper(root_->right_node->left_node) - heightHelper(root_->right_node->right_node);
        }
    }

    return root_;
}
void Gator_Tree::deleteNode(std::string ID) {
    this->deleteNodeHelper(this->root, ID);
}
Gator_Node* Gator_Tree::deleteNodeHelper(Gator_Node *root_, std::string ID) {
    // First seeing if it exists.
    if(!this->searchNodeExists(ID)){
        this->outputs.emplace_back("unsuccessful\n");
        return root_;
    }
    if(root_ == nullptr){
        return root_;
    }

    if(ID == root_->ID){
        if(root_->left_node == nullptr && root_->right_node == nullptr){
            this->outputs.emplace_back("successful\n");
            root_ = nullptr;
        }
        /*else if(root_->left_node == nullptr){
            Gator_Node* child = root_->right_node;
            root_ = child;
            child = nullptr;
        }
        else if(root_->right_node == nullptr){
            Gator_Node* child = root_->left_node;
            root_ = child;
            child = nullptr;
        }
        else{
            // Inorder successor found by traversing the left subtree in the right subtree for removing a node with 2 nodes.
            Gator_Node* child = root_->right_node;
            while(child->left_node != nullptr){
                child = child->left_node;
            }

            root_->name = child->name;
            root_->ID = child->ID;

            root_->right_node = deleteNodeHelper(root_->right_node, child->ID);
        }*/
    }

    root_ = changeBalanceAndHeight(root_);

    return root_;
}

void Gator_Tree::searchNodeByKey(std::string ID) {
    ID = this->verifyID(ID);
    if(!ID.empty()){
        std::vector<Gator_Node*> nodes = this->getTree();

        for(auto & node : nodes){
            if(node->ID == ID){
                this->outputs.emplace_back(node->name + "\n");
            }
        }
        this->outputs.emplace_back("unsuccessful\n");
    }

    this->outputs.emplace_back("unsuccessful\n");
}

void Gator_Tree::searchNodeByValue(std::string name){

    std::vector<Gator_Node*> nodes = this->getTree();
    std::vector<std::string> ID;
    std::string s;

    for(auto & node : nodes){
        if(node->name == name){
            ID.push_back(node->ID);
        }
    }
    if(!ID.empty()){
        if(ID.size() < 2){
            this->outputs.emplace_back(ID[0] + "\n");
        }

        for(auto& num : ID){
            s += num + " ";
        }
        this->outputs.emplace_back(s+"\n");
    }

    this->outputs.emplace_back("unsuccessful\n");
}

bool Gator_Tree::searchNodeExists(std::string ID) {
    ID = this->verifyID(ID);
    if(!ID.empty()){
        std::vector<Gator_Node*> nodes = this->getTree();

        for(auto & node : nodes){
            if(node->ID == ID){
                return true;
            }
        }
        return false;
    }
    return false;
}

void Gator_Tree::deleteNodeInorder(int N) {
    std::string ID = "00000000";
    int size = (int)this->getTree().size();
    if(N > size - 1)
        this->outputs.emplace_back("unsuccessful\n");
    else{
        ID = this->getTree().at(N)->ID;
        this->deleteNode(ID);
        this->outputs.emplace_back("successful\n");
    }
}

/*===== Data Validation =====*/
std::string Gator_Tree::verifyID(std::string& number){

    // Checking if the id is > 8 or less than 8.
    // ID must be 8 digits long.
    if(number.length() > 8 || number.length() < 8){
        return "";
    }

    // Checking if the ID contains only digits.
    for(char c : number){
        if(!isdigit(c)){
            return "";
        }
    }
    return number;
}

std::string Gator_Tree::verifyName(std::string& word){
    // Checking if the name contains only alphabetical characters and spaces, if applicable.
    for(char c : word){
        if(!isalpha(c) && !isspace(c)){
            return "";
        }
    }
    return word;
}