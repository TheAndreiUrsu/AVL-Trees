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

	test.inOrder();
	std::cout << std::endl;
	test.preOrder();
	std::cout << std::endl;
	test.postOrder();
	std::cout << std::endl;
	std::cout << "Tree height: " << test.treeHeight() << std::endl;

	return 0;
}

