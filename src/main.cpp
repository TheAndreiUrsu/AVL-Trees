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

   for(int i = 0; i < 99; ++i){
       test.insertNode(i);
   }

	cout << "----Debugging----" << endl;

	test.getTree();
	test.printHeightAndBalanceFactor();
    //using bfs to print out the nodes by level;


	cout << endl;

	std::vector<int> in_order = test.inOrder();
	std::cout << "In Order Traversal: ";
	for (int i : in_order) {
		cout << i << " ";
	}
	std::cout << std::endl;
	vector<int> pre_order = test.preOrder();
	std::cout << "Pre Order Traversal: ";
	for (int i : pre_order) {
		cout << i << " ";
	}	
	std::cout << std::endl;
	vector<int> post_order = test.postOrder();
	std::cout << "Post Order Traversal: ";
	for (int i : post_order) {
		cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}

