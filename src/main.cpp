#include <iostream>
#include <sstream>
#include <vector>
#include "avl_tree_node.h"
using namespace std;

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){

	AVL_Tree test;

	test.insertNode(25);
	test.insertNode(20);
	test.insertNode(36);
	test.insertNode(10);
	test.insertNode(22);
	test.insertNode(30);
	test.insertNode(40);
	test.insertNode(5);  
	test.insertNode(12);
	test.insertNode(28);
	test.insertNode(38);
	test.insertNode(48);
	test.insertNode(1);
	test.insertNode(8);
	test.insertNode(15);
	test.insertNode(45);
	test.insertNode(50);

	std::vector<int> in_order = test.inOrder();
	std::cout << "In Order Traversal: ";
	for (unsigned int i = 0; i < in_order.size(); ++i) {
		cout << in_order.at(i) << " ";
	}
	std::cout << std::endl;
	vector<int> pre_order = test.preOrder();
	std::cout << "Pre Order Traversal: ";
	for (unsigned int i = 0; i < pre_order.size(); ++i) {
		cout << pre_order.at(i) << " ";
	}	
	std::cout << std::endl;
	vector<int> post_order = test.postOrder();
	std::cout << "Post Order Traversal: ";
	for (unsigned int i = 0; i < post_order.size(); ++i) {
		cout << post_order.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Tree height: " << test.treeHeight() << std::endl;

	return 0;
}

