#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int item): data(item), left(nullptr), right(nullptr){}
};

class Tree {
  private:
  Node* root;
  public:
  Tree(): root(nullptr){}


  bool isEmpty(){
    return root == nullptr;
  }
  void insertNode(int data){
    Node* newNode = new Node(data);
    if(isEmpty()){
      root = newNode;
      cout << "Node added at the root " << endl;
      return;
    }
    Node* current = root;
    Node* parent = nullptr;

    while( current != nullptr){
      parent = current;

      if( parent->data == data){
        cout << "No two element can be the same in BST " <<endl;
        delete newNode;
        return;
      }
      else if(parent->data < data){
        current = parent->right;
      }
      else {
        current = current->left;
      }
    }

    if(parent->data > data){
      parent->left  = newNode;
    }

    else {
      parent->right = newNode;
    }

    cout << "Node added Successfully " << endl;

  }
  Node* getRoot(){
    return root;
  }
  void inOrderTraversal(Node* root){
    if(root != nullptr){
      inOrderTraversal(root->left);
      cout << root->data << " ";
      inOrderTraversal(root->right);
    }
  }
  
  void deleteNode(int data){
    Node* current = root;
    Node* parent = nullptr;
    while(current != nullptr){
      parent = current;
      if(parent->data == data){
        break;
      }
      else if(parent->data > data){
        current = parent->left;
      }
      else {
        current = parent->right;
      }
    }

    Node* temp = parent->right;
    delete parent;
    if(temp != nullptr){
    current = root;
    parent  = nullptr;

    while(current != nullptr){
      parent = current;
      current = parent->left;
    }
    
    parent->right = temp;
    }

  }

















};









int main(){

  Tree tree;
  tree.insertNode(1);
  tree.insertNode(2);
  tree.insertNode(3);
  tree.insertNode(4);
  tree.insertNode(12);
  tree.insertNode(5);
  tree.insertNode(0);
  tree.insertNode(12);

  tree.inOrderTraversal(tree.getRoot());
  tree.deleteNode(12);








  return 0;
}
