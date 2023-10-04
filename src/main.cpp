#include <iostream>
#include <sstream>
#include <vector>
#include "gator_id_app.h"
using namespace std;

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

string verifyID(istringstream& in);
string verifyName(istringstream& in);

void insert(Gator_Tree& gatorTree, const string& name, int ID);
void remove(Gator_Tree& gatorTree, int ID);
void search(Gator_Tree& gatorTree, int ID);
void search(Gator_Tree& gatorTree, const string& name);

void printInorder(Gator_Tree& gatorTree);
void printPreorder(Gator_Tree& gatorTree);
void printPostorder(Gator_Tree& gatorTree);
void printLevelCount(Gator_Tree& gatorTree);
void removeInorder(int N);

int main(){
    GatorApp App;
    App.run();

    /*int commands;
    cin >> commands;

    while(commands > 0){
        string command;
        cin >> command;

        if(command.compare("insert") == 0){

        }

        commands--;
    }

    Gator_Tree gatorTree;

    insert(gatorTree, "John", 12345678);
    insert(gatorTree, "Alice", 23456789);
    insert(gatorTree, "Bob", 34567890);
    insert(gatorTree, "Charlie", 45678901);
    insert(gatorTree, "David", 56789012);
    insert(gatorTree, "Eve", 67890123);
    insert(gatorTree, "Frank", 78901234);
    insert(gatorTree, "Grace", 89012345);
    insert(gatorTree, "Hannah", 90123456);
    insert(gatorTree, "Isabel", 91234567);
    insert(gatorTree, "Jack", 82345678);
    insert(gatorTree, "Karen", 93456789);
    insert(gatorTree, "Liam", 14567890);
    insert(gatorTree, "Mia", 25678901);
    insert(gatorTree, "Nathan", 36789012);
    insert(gatorTree, "Olivia", 47890123);
    insert(gatorTree, "Peter", 58901234);
    insert(gatorTree, "Quinn", 69012345);
    insert(gatorTree, "Rachel", 70123456);
    insert(gatorTree, "Samuel", 81234567);
    insert(gatorTree, "Tina", 92345678);
    insert(gatorTree, "Ulysses", 34561234);
    insert(gatorTree, "Victoria", 45672345);
    insert(gatorTree, "William", 56783456);
    insert(gatorTree, "Xena", 67894567);
    insert(gatorTree, "Yvonne", 78905678);
    insert(gatorTree, "Zachary", 89016789);
    insert(gatorTree, "Ashley", 90127890);
    insert(gatorTree, "Benjamin", 98789012);
    insert(gatorTree, "Catherine", 87690123);
    insert(gatorTree, "Daniel", 76501234);
    insert(gatorTree, "Emily", 65412345);
    insert(gatorTree, "Felix", 54323456);
    insert(gatorTree, "Gabriella", 43234567);
    insert(gatorTree, "Henry", 32145678);
    insert(gatorTree, "Isabella", 21056789);
    insert(gatorTree, "Jacob", 10967890);
    insert(gatorTree, "Katherine", 98778901);
    insert(gatorTree, "Liam", 87689012);
    insert(gatorTree, "Mia", 76590123);
    insert(gatorTree, "Nathan", 65401234);
    insert(gatorTree, "Olivia", 54312345);
    insert(gatorTree, "Peter", 43223456);
    insert(gatorTree, "Quinn", 32134567);
    insert(gatorTree, "Rachel", 21045678);
    insert(gatorTree, "Samuel", 98756789);
    insert(gatorTree, "Tina", 87667890);
    insert(gatorTree, "Ulysses", 76578901);
    insert(gatorTree, "Victoria", 65489012);
    insert(gatorTree, "William", 54390123);
    insert(gatorTree, "Xena", 43201234);
    insert(gatorTree, "Yvonne", 32112345);
    insert(gatorTree, "Zachary", 21023456);

    search(gatorTree, 86230819);
    search(gatorTree, "Alfred");
    search(gatorTree, "Andrei");
    printInorder(gatorTree);
    printPostorder(gatorTree);
    printPreorder(gatorTree);
    printLevelCount(gatorTree);
*/
	return 0;
}

string verifyID(istringstream& in){
    string word;
    in >> word;

    if(word.length() > 8){
        return "";
    }

    for(char c : word){
        if(!isalpha(c)){
            return "";
        }
    }
    return word;
}

string verifyName(istringstream& in){
    string word;
    in >> word;

    if(word.length() > 8){
        return "";
    }

    for(char c : word){
        if(!isalpha(c) && !isdigit(c)){
            return "";
        }
    }
    return word;
}

void insert(Gator_Tree& gatorTree, const string& name, int ID){
    gatorTree.insertNode(name, ID);
}

void remove(Gator_Tree& gatorTree, int ID){
    gatorTree.deleteNode(ID);
}

void search(Gator_Tree& gatorTree, int ID){
    string s = gatorTree.searchNodeByKey(ID);
    cout << s;
}
void search(Gator_Tree& gatorTree, const string& name){
    string s = gatorTree.searchNodeByValue(name);
    cout << s;
}

void printInorder(Gator_Tree& gatorTree){
    vector<string> inorder = gatorTree.inOrder();
    for(size_t i = 0; i < inorder.size(); ++i){
        cout << inorder[i];
        if(i < inorder.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;
}
void printPreorder(Gator_Tree& gatorTree){
    vector<string> preorder = gatorTree.preOrder();
    for(size_t i = 0; i < preorder.size(); ++i){
        cout << preorder[i];
        if(i < preorder.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;
}
void printPostorder(Gator_Tree& gatorTree){
    vector<string> postorder = gatorTree.postOrder();
    for(size_t i = 0; i < postorder.size(); ++i){
        cout << postorder[i];
        if(i < postorder.size() - 1){
            cout << ", ";
        }
    }
    cout << endl;
}
void printLevelCount(Gator_Tree& gatorTree){
    cout << to_string(gatorTree.getLevelCount()) << endl;
}

void removeInorder(int N){

}