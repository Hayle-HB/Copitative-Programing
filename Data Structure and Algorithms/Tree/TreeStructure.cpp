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

    int insertNode(int data) {
        Node* newNode = new Node();
        newNode->item = data;
        newNode->left = newNode->right = nullptr;

        if (Root == nullptr) {
            Root = newNode;
            return 1;
        }

        Node* current = Root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (parent->item == data) {
                delete newNode; // Release memory for duplicate value
                return -1;      // Duplicate value
            } else if (parent->item > data) {
                current = parent->left;
            } else {
                current = parent->right;
            }
        }

        if (parent->item > data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        return 1; // Node added successfully
    }

};

int main() {
    Tree tree;

    int i = tree.insertNode(12);
    if (i != -1) {
        cout << "Node added Successfully " << endl;
    } else {
        cout << "Node duplicate " << endl;
    }

    int j = tree.insertNode(10);
    if (j != -1) {
        cout << "Node added Successfully " << endl;
    } else {
        cout << "Node duplicate " << endl;
    }

    int k = tree.insertNode(15);
    if (k != -1) {
        cout << "Node added Successfully " << endl;
    } else {
        cout << "Node duplicate " << endl;
    }

    return 0;
}
