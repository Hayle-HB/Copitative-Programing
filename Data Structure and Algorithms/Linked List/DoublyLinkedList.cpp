#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

struct DoubleLinkedList {
  private:
    Node* head;
    Node* tail;
  public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

  void insertAtEnd(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr){
      head = tail = newNode;
    }
    else{

    tail->next = newNode;
    newNode->prev = tail;

    tail = newNode;
    }
  }
  void insertAtFirst(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(head == nullptr){
      head = tail = newNode;
    }
    else {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
    }
  }
  void insertAtAfterNode(int data, int node) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    Node* forWard = head;
    Node* backWord = tail;

    while (forWard != nullptr || backWord != nullptr) {
        if (forWard != nullptr && forWard->data == node) {
            Node* temp = forWard->next;
            forWard->next = newNode;
            newNode->prev = forWard;
            newNode->next = temp;
            if (temp != nullptr) {
                temp->prev = newNode;
            }
            break;
        } else if (backWord != nullptr && backWord->data == node) {
            Node* temp = backWord->prev;
            backWord->prev = newNode;
            newNode->next = backWord;
            newNode->prev = temp;
            if (temp != nullptr) {
                temp->next = newNode;
            }
            break;
        }
        
        if (forWard != nullptr) {
            forWard = forWard->next;
        }
        
        if (backWord != nullptr) {
            backWord = backWord->prev;
        }
    }
}
  void displayAllNodes(){
    Node* current = head;
    while(current != nullptr){
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl << endl;
  }
  void deleteAtFirst(){
    if(head == nullptr){
      cout << "No element is found to be deleted ";
      return;
    }
    Node* temp = head->next;
    delete head;
    if (temp != nullptr){
        head = temp;
        head->prev = nullptr;
    }
    else {
        head = nullptr;
    }
  }
  void deleteAtEnd(){
    if(head == nullptr){
      cout << "No element is found to be deleted ";
      return;
    }
    if(head == tail){
      delete tail;
      head = tail = nullptr;
      return;
    }

    Node* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = nullptr;
  }
  void deleteSpecificNode(int data){
    if(head == nullptr){
      cout << "No element is found to be deleted ";
      return;
    }
    Node* current = head;

    while(current != nullptr){
        if(current->data == data){
          Node* tempPrev = current->prev;
          Node* tempNext = current->next;

          if(tempPrev != nullptr){
            tempPrev->next = tempNext;
          }
          else {
            head = tempNext;
          }

          if(tempNext != nullptr){
            tempNext->prev = tempPrev;
          }
          else {
            tail  = tempPrev;
          }
          delete current;
          break;
        }
        current = current->next;
    }
  }
};





int main(){

  DoubleLinkedList list;
  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);
  list.insertAtEnd(4);
  list.insertAtEnd(5);
  list.insertAtFirst(10);
  list.insertAtFirst(20);
  list.insertAtFirst(30);
  list.insertAtFirst(40);
  list.insertAtFirst(50);
  list.displayAllNodes();
  cout << endl;
  list.insertAtAfterNode(100, 30);
  list.displayAllNodes();
  list.deleteAtFirst();
  list.displayAllNodes();
  list.deleteAtEnd();
  list.displayAllNodes();

  list.deleteSpecificNode(100);
  list.displayAllNodes();


  return 0;
}
