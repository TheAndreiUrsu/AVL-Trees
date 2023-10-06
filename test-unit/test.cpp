#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/gator_tree.h"
#include <algorithm>
#include <sstream>

	/*To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test*/



// Testing invalid input
TEST_CASE("Test Incorrect Commands", "[incorrect_commands]"){
    Gator_Tree gatorTree;

    // Stores the outputs based on the command run.
    std::vector<std::string> outputs;

    // Inserting commands with incorrect input
    gatorTree.insertNode("A11y","45679999"); // outputs[0]
    gatorTree.insertNode("James", "1234"); // outputs[1]
    gatorTree.insertNode("A11y","0000006789"); // outputs[2]

    // Attempting to delete a node with incorrect input
    std::string input = "Ally";
    gatorTree.deleteNode(input); // outputs[3]

    // Inserting a node with ID and name swapped
    gatorTree.insertNode("12312414", "Jimothy"); // outputs[4]

    outputs = gatorTree.getOutputs();

    // When searching for a node, it will be successful if it has been inserted in the tree successfully
    REQUIRE(outputs[0] == "unsuccessful\n");
    REQUIRE(outputs[1] == "unsuccessful\n");
    REQUIRE(outputs[2] == "unsuccessful\n");

    // Ensuring deletion was unsuccessful
    REQUIRE(outputs[3] == "unsuccessful\n");

    // Ensuring searching for a non-existent node was unsuccessful
    REQUIRE(outputs[4] == "unsuccessful\n");
}

TEST_CASE("Testing Edge Cases", "[edge_cases]"){
    Gator_Tree gatorTree;

    std::vector<std::string> outputs;

    // removing non-existent node
    // delete node will return "successful" or "unsuccessful" if the node exists.
    gatorTree.deleteNode("12345678"); // outputs[0]

    // inserting a node and removing it with no children
    gatorTree.insertNode("Alice", "12345678"); // outputs[1]
    gatorTree.deleteNode("12345678"); // outputs[2]

    gatorTree.insertNode("Alice", "12345678"); // outputs[3]
    gatorTree.insertNode("James", "78945621"); // outputs[4]
    gatorTree.deleteNode("78945621"); // outputs[5]
    gatorTree.searchNodeByKey("12345678"); // outputs[6]


    outputs = gatorTree.getOutputs();
    // inserting a node and removing it with 1 child

    REQUIRE(outputs[0] == "unsuccessful\n");
    REQUIRE(outputs[1] == "successful\n");
    REQUIRE(outputs[2] == "successful\n");
    REQUIRE(outputs[3] == "successful\n");
    REQUIRE(outputs[4] == "successful\n");
    REQUIRE(outputs[5] == "successful\n");
    REQUIRE(outputs[6] == "successful\n");



}
/*
TEST_CASE("Testing Rotation Cases", "[rotation_cases]"){
    Gator_Tree gatorTree;

    // left-left rotation case
    gatorTree.insertNode("Alice", "86230819");
    gatorTree.insertNode("Bob", "86230817");
    gatorTree.insertNode("Jade", "86230777");

    std::vector<std::string> preOrder1 = gatorTree.preOrder();
    std::vector<std::string> result1 = {"Bob", "Jade", "Alice"};

    gatorTree.deleteNode("86230819");
    gatorTree.deleteNode("86230817");
    gatorTree.deleteNode("86230777");

    // right-right rotation case
    gatorTree.insertNode("Alice", "86230819");
    gatorTree.insertNode("Bob", "86230820");
    gatorTree.insertNode("Jade", "86230888");

    std::vector<std::string> preOrder2 = gatorTree.preOrder();
    std::vector<std::string> result2 = {"Bob", "Alice", "Jade"};

    gatorTree.deleteNode("86230819");
    gatorTree.deleteNode("86230820");
    gatorTree.deleteNode("86230888");

    // left-right rotation case
    gatorTree.insertNode("Alice", "86230819");
    gatorTree.insertNode("Bob", "86230817");
    gatorTree.insertNode("Jade", "86230818");

    std::vector<std::string> preOrder3 = gatorTree.preOrder();
    std::vector<std::string> result3 = {"Jade", "Bob", "Alice"};

    gatorTree.deleteNode("86230819");
    gatorTree.deleteNode("86230817");
    gatorTree.deleteNode("86230818");

    // right-left rotation case
    gatorTree.insertNode("Alice", "86230819");
    gatorTree.insertNode("Bob", "86230821");
    gatorTree.insertNode("Jade", "86230820");

    std::vector<std::string> preOrder4 = gatorTree.preOrder();
    std::vector<std::string> result4 = {"Jade", "Alice", "Bob"};

    gatorTree.deleteNode("86230819");
    gatorTree.deleteNode("86230817");
    gatorTree.deleteNode("86230818");

    REQUIRE(preOrder1 == result1);
    REQUIRE(preOrder2 == result2);
    REQUIRE(preOrder3 == result3);
    REQUIRE(preOrder4 == result4);
}

TEST_CASE("Testing Deletion Cases", "[deletion_cases]"){
    Gator_Tree gatorTree;

    std::vector<std::string> successes;

    // inserting a node and removing it with no children
    gatorTree.insertNode("Alice", "12345678");
    successes.push_back(gatorTree.deleteNode("12345678"));

    // inserting a node and removing it with 1 child
    gatorTree.insertNode("Alice", "12345678");
    gatorTree.insertNode("James", "78945621");
    successes.push_back(gatorTree.deleteNode("78945621"));

    // inserting a node and removing it with 2 children
    gatorTree.insertNode("Alice", "12345678");
    gatorTree.insertNode("James", "78945621");
    gatorTree.insertNode("Jade", "80004569");
    successes.push_back(gatorTree.deleteNode("78945621"));

    REQUIRE(successes[0] == "successful\n");
    REQUIRE(successes[1] == "successful\n");
    REQUIRE(successes[1] == "successful\n");
}

*/
/*TEST_CASE("AVL Insert Large", "[large_insert]"){

    struct node{
        std::string id;
        std::string name;
    };

    Gator_Tree gatorTree;
    std::vector<node> expected_output;

    // https://www.geeksforgeeks.org/program-generate-random-alphabets/
    std::string alphabet[26] = {
            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
            "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
            "U", "V", "W", "X", "Y", "Z"
    };

    // verifying insert 100 nodes
    for(int i = 0; i < 100; ++i){
        std::string name = "Node " + alphabet[rand() % 26];

        int ID_int = i + 10000000;
        std::string ID_str = std::to_string(ID_int);

        node dummy;
        dummy.id = ID_str;
        dummy.name = name;

        expected_output.push_back(dummy);
        gatorTree.insertNode(name, ID_str);
    }

    // struct method: https://stackoverflow.com/questions/37368787/c-sort-one-vector-based-on-another-one 9 upvoted answer
    std::vector<std::string> inOrder = gatorTree.inOrder();
    std::sort(expected_output.begin(), expected_output.end(), [](const auto& i, const auto& j){
        return i.id < j.id;
    });
    std::vector<std::string> expected_in_order;
    for(auto& i : expected_output){
        expected_in_order.push_back(i.name);
    }

    REQUIRE(inOrder == expected_in_order);
    REQUIRE(expected_output.size() == inOrder.size());

    // randomly deleting 10 nodes
    for(int i = 0; i < 10; i++){
        int rand_ID = rand() % 100 + 10000000;
        expected_output.erase(std::remove_if(expected_output.begin(), expected_output.end(), [rand_ID](const node& node)->bool {
            return node.id == rand_ID;
        }), expected_output.end());

        gatorTree.deleteNode(rand_ID);
    }
    expected_in_order.clear();
    std::sort(expected_output.begin(), expected_output.end(), [](const auto& i, const auto& j){
        return i.id < j.id;
    });
    for(auto& i : expected_output){
        expected_in_order.push_back(i.name);
    }

    inOrder = gatorTree.inOrder();

    REQUIRE(inOrder == expected_in_order);
    REQUIRE(gatorTree.getTree().size() == 90);
    REQUIRE(inOrder.size() == expected_in_order.size());

    // verify remaining 90 nodes with inorder


}*/

