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
	test.insertNode(3);
	test.insertNode(2);
	test.insertNode(5);

	test.inOrder();

	return 0;
}

