#include <iostream>
#include "tree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

int main(){

	// Testing insert. 
	AVL_Tree test;

	AVL_Node* root = test.insertNode("James", "86230819");
	test.insertNode("Barbara", "96238791", root);
	test.insertNode("Elias", "78941364", root);
	test.printTree();

	return 0;
}

