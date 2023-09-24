#include <iostream>
#include "avl_tree_node.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){

	// Testing insert. 

	AVL_Tree AT;
	AT.insertNode("James", 86230819);
	AT.insertNode("Barbara", 96238791);
	AT.printTree();

	return 0;
}

