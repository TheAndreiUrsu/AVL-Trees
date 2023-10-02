#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/avl_tree_node.h"
#include <stdlib.h>
#include <algorithm>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/


TEST_CASE("BST Insert", "[flag]"){
	
		AVL_Tree tree;   // Create a Tree object
		tree.insertNode(1);
		tree.insertNode(2);
		tree.insertNode(3);
        tree.getTree();
		std::vector<int> actualOutput = tree.inOrder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	
	//REQUIRE(1 == 1);
}

TEST_CASE("BST Insert Large", "[flag]"){
    AVL_Tree inputTree;
    std::vector<int> expectedOutput, actualOutput;

    for(int i = 0; i < 50; i++)
    {
        int randomInput = rand();
        if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
        {
            expectedOutput.push_back(randomInput);
            inputTree.insertNode(randomInput);
        }
    }

    actualOutput = inputTree.inOrder();
    for(int i : actualOutput){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::sort(expectedOutput.begin(), expectedOutput.end());
    for(int i : expectedOutput){
        std::cout << i << " ";
    }
    REQUIRE(expectedOutput.size() == actualOutput.size());
    //REQUIRE_FALSE(expectedOutput == actualOutput);    //This assertion can be wrong. Don't use
    std::sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == actualOutput);

}