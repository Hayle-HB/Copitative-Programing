#include <iostream>
using namespace std;

struct Node {
    int item;
    Node* left;
    Node* right;
    Node(int data): item(data), left(nullptr), right(nullptr){}
};

class Tree {
    private: Node* root;
    public:
    Tree(): root(nullptr){}

    Node* getRoot(){
        return root;
    }
    void insert(int data){
        Node* newNode = new Node(data);

        if(root == nullptr){
            root = newNode;
            cout << "The first Data is Stored at Root " <<endl;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;

        while(current != nullptr){
            parent = current;
            if(current->item == data){
                delete newNode;
                cout << "WE can handle the Same Element in BST" << endl;
                return;
            }
            else if(current->item > data){
                current = parent->left;
            }
            else {
                current = current->right; 
            }
        }
        if (parent->item < data) {
            parent->right = newNode;
            cout << "Data is Stored at the right part of the Tree " << endl;
        }
        else {
            parent->left = newNode;
            cout << "Data is Stored at the left part of the Tree " << endl;
        }

    }
    void inOrderTraversal(Node* root){
        if(root != nullptr){
            inOrderTraversal(root->left);
            cout << root->item << "  ";
            inOrderTraversal(root->right);
        }
    }
    void deleteNode(int data){
        
    }












};


int main(){

    Tree tree;
    tree.insert(10);
    tree.insert(2);
    tree.insert(11);
    tree.insert(11);
    tree.inOrderTraversal(tree.getRoot());



    return 0;
}