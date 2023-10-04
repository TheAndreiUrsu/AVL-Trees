#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/gator_tree.h"
#include <cstdlib>
#include <algorithm>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/


TEST_CASE("BST Insert", "[flag]"){
	
		Gator_Tree tree;   // Create a Tree object
		tree.insertNode("j",1);
		tree.insertNode("j",2);
		tree.insertNode("j",3);
        tree.getTree();
		std::vector<int> actualOutput = tree.inOrder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	
	//REQUIRE(1 == 1);
}

TEST_CASE("BST Insert Large", "[flag]"){
    Gator_Tree inputTree;
    std::vector<int> expectedOutput, actualOutput;

    for(int i = 0; i < 100000; i++)
    {
        int randomInput = rand();
        if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
        {
            expectedOutput.push_back(randomInput);
            inputTree.insertNode("j",randomInput);
        }
    }

    actualOutput = inputTree.inOrder();
    REQUIRE(expectedOutput.size() == actualOutput.size());
    //REQUIRE_FALSE(expectedOutput == actualOutput);    //This assertion can be wrong. Don't use
    std::sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == actualOutput);

}