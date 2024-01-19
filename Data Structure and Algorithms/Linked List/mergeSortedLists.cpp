#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class LinkedList {
  private: Node* head;
  public: LinkedList() : head(nullptr){}
  void insertAtEnd(int data){
    Node* newNode  = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if(head == nullptr){
      head = newNode;
      return;
    }
    Node* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = newNode;
  }
  
  void display(){
    if(head == nullptr){
      cout << "No element is found " << endl;
      return;
    }
    Node* current = head;
    while(current != nullptr){
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl << endl;
  }
void mergeSortedLists(const LinkedList& list1, const LinkedList& list2) {
    this->~LinkedList();  // Clear the current list before merging
    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr || current2 != nullptr) {
        int newData;

        if (current1 == nullptr) {
            newData = current2->data;
            current2 = current2->next;
        } else if (current2 == nullptr) {
            newData = current1->data;
            current1 = current1->next;
        } else {
            if (current2->data > current1->data) {
                newData = current1->data;
                current1 = current1->next;
            } else {
                newData = current2->data;
                current2 = current2->next;
            }
        }

        insertAtEnd(newData);
    }
}



int deleteElement(int data) {
    Node* current = head;
    Node* prev = nullptr;

    if (head == nullptr) {
        return -1; // no element is found to delete 
    }

    if (head->data == data) {
        return 1;
    }

    prev = head;
    current = current->next;

    while (current != nullptr) {
        if (current->data == data) {
            prev->next = current->next;
            delete current;
        }
        prev = current;
        current = current->next;
    }

    return -1;
} 










  ~LinkedList(){
    Node* current = head;
    while(current != nullptr){
      Node* temp = current;
      current = current->next;
      delete temp;
    }
  }


};

int main(){

  LinkedList list;
  LinkedList list1, list2;
  list1.insertAtEnd(1);
  list1.insertAtEnd(2);
  list1.insertAtEnd(2);
  list1.insertAtEnd(2);
  list1.insertAtEnd(2);
  list1.insertAtEnd(2);
  list1.insertAtEnd(7);
    cout << endl;
    list1.display();
  list2.insertAtEnd(9);
  list2.insertAtEnd(10);
  list2.insertAtEnd(11);
  list2.insertAtEnd(12);
  list2.insertAtEnd(13);
  list2.insertAtEnd(14);
  list2.insertAtEnd(15);
  list2.insertAtEnd(16);
    cout << endl;
    list2.display();


    list.mergeSortedLists(list1, list2);
    list.display();

    list.deleteElement(2);
    list.display();






  return 0;
}