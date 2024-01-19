#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class QueueList {
  private:
    Node* back;
    Node* front;
  public:
  QueueList(): back(nullptr), front(nullptr){}
  bool isEmpty(){
    return front == nullptr;
  }
  void enqueue(int data){
    Node* newNode = new Node();
    newNode->data = data;
    if(isEmpty()){
      back = front = newNode;
    }

    newNode->next = back;
    back = newNode;
  }
  int dequeueBack(){
    if(isEmpty()){
      cout << "UnderFlow" << endl;
      return -1;
    }
    int num = back->data;
    Node* temp = back->next;
    delete back;
    back = temp;
  return num;
  }
  void display(){
    Node* current = back;
    while(current != front){
      cout << current->data << "  ";
      current = current->next;
    }
    cout << current->data << " ";
    cout << endl;
  }

};




int main(){

  QueueList list;
  cout <<   list.isEmpty() << endl;
  list.enqueue(1);
  list.enqueue(2);
  list.enqueue(3);
  list.enqueue(4);
  list.enqueue(5);
  list.enqueue(6);
  list.enqueue(7);
  list.display();
  cout << "Dequeue: " << list.dequeueBack() << endl;
  list.display();
  






  return 0;
}