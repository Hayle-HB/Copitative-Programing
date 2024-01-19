#include <iostream>
using namespace std;


struct Node{
  int data;
  Node* next;
};

class LinkedList {
  private:
  Node* head;
  public:
  LinkedList(): head(nullptr){}

  void display(){
    Node* current = head;
    if(head == nullptr){
      cout << "List is empty" << endl;
      return;
    }
    while(current != nullptr){
      cout << current->data << endl;
      current = current->next;
    }
  }
  void insertAtBegin(int value){
     Node* newNode = new Node();
     newNode->data = value;
     newNode->next = head;
     head = newNode;
     cout << "Node added Successfully" << endl;
  }
  
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        cout << "Node added at the end Successfully" << endl;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    cout << "Node added at the end Successfully" << endl;
}

void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (head == nullptr) {
        if (position != 1) {
            cout << "No element is at position " << position << endl;
            return;
        }
        head = newNode;
        cout << "Node added at position " << position << " successfully" << endl;
        return;
    }

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Node added at position " << position << " successfully" << endl;
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "No element is at position " << position - 1 << endl;
        return;
    }

    Node* temp = current->next;
    current->next = newNode;
    newNode->next = temp;
    cout << "Node added at position " << position << " successfully" << endl;
}

void deleteAtBegin() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr; // Set head to nullptr after deleting the only node
        cout << "Node deleted successfully" << endl;
        return;
    }

    Node* temp = head->next;
    int temp2 = head->data;
    delete head;
    head = temp;
    cout << temp2 << "Node deleted successfully" << endl;
}


void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Node deleted successfully" << endl;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    cout << "The last element deleted successfully" << endl;
}

void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    } else if (position == 1) {
        deleteAtBegin();
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    for (int i = 1; i < position && current != nullptr; i++) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid element position " << position << endl;
        return;
    }

    if (previous != nullptr) {
        // If not deleting the first node
        previous->next = current->next;
        delete current;
    } else {
        // If deleting the first node
        head = current->next;
        delete current;
    }

    cout << "Node deleted successfully" << endl;
}

};


int main(){

  LinkedList list;
  list.insertAtBegin(10);
  list.insertAtBegin(20);
  list.insertAtBegin(30);
  list.insertAtBegin(40);

  list.display();
  list.deleteAtBegin();
  list.display();
  list.deleteAtEnd();
  list.display();
  list.deleteAtPosition(2);
  list.display();








  return 0;
}