#include <iostream>
using namespace std;

struct Node {
  int item;
  Node* left;
  Node* right;
};

class Tree {
private:
    Node* Root;

public:
    Tree() : Root(nullptr) {}

void insertNode(int data) {
    Node* newNode = new Node();
    if (Root == nullptr) {
        Root = newNode;
        cout << "Data inserted successfully at Root " << endl;
        return;
    }

    Node* current = Root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        if (parent->item <= data) {
            current = parent->right;
        } else {
            current = parent->left;
        }
    }

    // Handle the case when the tree is empty
    if (parent == nullptr) {
        cout << "Error: parent is nullptr" << endl;
        delete newNode; // Free the allocated memory for the new node
        return;
    }

    // Insert the new node based on its value
    if (parent->item <= data) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }

    newNode->left = nullptr;
    newNode->right = nullptr;
    cout << "Data inserted successfully" << endl;
}

};

int main() {
    Tree tree;
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(3);

    return 0;
}
