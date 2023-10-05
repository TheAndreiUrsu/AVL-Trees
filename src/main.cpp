#include <iostream>
#include <vector>
#include <fstream>
#include "gator_tree.h"
using namespace std;

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

string verifyID(string& number);
string verifyName(string& word);

void insert(Gator_Tree& gatorTree, const string& name, int ID);
void remove(Gator_Tree& gatorTree, int ID);
void search(Gator_Tree& gatorTree, int ID);
void search(Gator_Tree& gatorTree, const string& name);

void printInorder(Gator_Tree& gatorTree);
void printPreorder(Gator_Tree& gatorTree);
void printPostorder(Gator_Tree& gatorTree);
void printLevelCount(Gator_Tree& gatorTree);
void removeInorder(Gator_Tree& gatorTree, int N);

int main(int argc, char* argv[]){

    ifstream input_txt(argv[2]);

    if(!input_txt.is_open())
        return 1;

    Gator_Tree gatorTree;

    string command_cnt_str;
    getline(input_txt, command_cnt_str);
    int command_cnt = stoi(command_cnt_str);

    while(command_cnt > 0){
        string command;
        string name;
        string id_str;

        getline(input_txt, command, ' ');

        // Case: insert "NAME" 12345678
        if(command == "insert"){
            // Get arguments.
            getline(input_txt, name, '"');
            getline(input_txt, name, '"');
            getline(input_txt, id_str);

            // Check the arguments.
            name = verifyName(name);
            id_str = verifyID(id_str);

            // If name or id is empty, command was unsuccessful.
            if(name.empty() || id_str.empty())
                cout << "unsuccessful" << endl;
            else{
               insert(gatorTree, name, stoi(id_str)); // Attempting to insert node if it doesn't exist.
            }
            cout << "successful" << endl;
        }

        // Case: remove 12345678
        else if(command == "remove"){
            // Get arguments.
            getline(input_txt, id_str);
            id_str = verifyID(id_str);
            if(id_str.empty())
                cout << "unsuccessful" << endl;
            else{
                remove(gatorTree,stoi(id_str));
            }
            cout << "successful" << endl;
        }

        // Case: search 12345678 or search "Jeff"
        else if(command == "search"){
            string next;
            // Get arguments.
            // Checking if it's the case of search 12345678 or search "Jeff"
            if(next.find('"') != string::npos){
                getline(input_txt, name, '"');
                getline(input_txt, name, '"');

                name = verifyName(name);
                if(name.empty())
                    cout << "unsuccessful" << endl;
                else
                    search(gatorTree, name);
            }
            else{
                getline(input_txt, id_str);

                id_str = verifyID(id_str);
                if(id_str.empty())
                    cout << "unsuccessful" << endl;
                else
                    search(gatorTree, stoi(id_str));
            }
        }

        // Case: printInorder
        else if(command == "printInorder"){
            printInorder(gatorTree);
        }

        // Case: printPreorder
        else if(command == "printPreorder"){
            printPreorder(gatorTree);
        }

        // Case: printPostorder
        else if(command == "printPostorder"){
            printPostorder(gatorTree);
        }

        // Case: printLevelCount
        else if(command == "printLevelCount"){
            printLevelCount(gatorTree);
        }

        // Case: removeInorder
        else if(command == "removeInorder"){
            string N;
            int x;
            getline(input_txt, N);

            try{
                x = stoi(N);
            }
            catch (exception& e){
                cout << "unsuccessful" << endl;
            }

            if(x > static_cast<int>(gatorTree.getTree().size()))
                cout << "unsuccessful" << endl;
            else
                removeInorder(gatorTree, stoi(N));
        }
        else{
            cout << "unsuccessful" << endl;
        }

        command_cnt--;
    }

	return 0;
}

string verifyID(string& number){

    if(number.length() > 8){
        return "";
    }

    for(char c : number){
        if(!isalpha(c)){
            return "";
        }
    }
    return number;
}

string verifyName(string& word){
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

void removeInorder(Gator_Tree& gatorTree, int N){
    gatorTree.deleteNodeInorder(N);
}
