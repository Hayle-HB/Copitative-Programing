#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* head = NULL;
void insertAtFirst(int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}


void displayAll(){
  Node* current = head;
  while(current != nullptr){
    cout << current->data << " ";
    current = current->next;
  }
}


void insertAtEnd(int data){
  Node* current = head;
  while(current->next!= nullptr){
    current = current->next;
  }

  Node* newNode = new Node();
  newNode->data = data;
  current->next = newNode;
}

void deleteStskldjf(int data){
  k
}




int main(){


  insertAtFirst(1);
  insertAtFirst(2);
  insertAtFirst(3);
  insertAtFirst(4);
  insertAtFirst(5);
  insertAtEnd(-1);
  insertAtEnd(1);
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(4);
  insertAtEnd(5);

  displayAll();






  return 0;
}