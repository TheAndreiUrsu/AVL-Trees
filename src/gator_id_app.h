#include "gator_tree.h"
#include <sstream>
#include <iostream>
using namespace std;

class GatorApp{
private:
    Gator_Tree gatorTree;
public:
    GatorApp()= default;

    void run(){
        int commands;
        cin >> commands;

        while(commands > 0){
            string command;
            cin >> command;

            if(command == "insert"){
                string name = this->verifyName(dynamic_cast<istringstream &>(getline(cin, name)));
                int value = this->verifyID(getline(cin, value));
                cin >> name >> value;
                name = this->verifyName()
                this->insert("placeholder", 12345678);
            }

            this->printInorder();

            commands--;
        }
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

    void insert(const string& name, int ID){
        this->gatorTree.insertNode(name, ID);
    }

    void remove(int ID){
        this->gatorTree.deleteNode(ID);
    }

    void search(int ID){
        string s =  this->gatorTree.searchNodeByKey(ID);
        cout << s;
    }
    void search(const string& name){
        string s =  this->gatorTree.searchNodeByValue(name);
        cout << s;
    }

    void printInorder(){
        vector<string> inorder =  this->gatorTree.inOrder();
        for(size_t i = 0; i < inorder.size(); ++i){
            cout << inorder[i];
            if(i < inorder.size() - 1){
                cout << ", ";
            }
        }
        cout << endl;
    }
    void printPreorder(){
        vector<string> preorder =  this->gatorTree.preOrder();
        for(size_t i = 0; i < preorder.size(); ++i){
            cout << preorder[i];
            if(i < preorder.size() - 1){
                cout << ", ";
            }
        }
        cout << endl;
    }
    void printPostorder(){
        vector<string> postorder =  this->gatorTree.postOrder();
        for(size_t i = 0; i < postorder.size(); ++i){
            cout << postorder[i];
            if(i < postorder.size() - 1){
                cout << ", ";
            }
        }
        cout << endl;
    }
    void printLevelCount(){
        cout << to_string( this->gatorTree.getLevelCount()) << endl;
    }

    void removeInorder(int N){

    }
};