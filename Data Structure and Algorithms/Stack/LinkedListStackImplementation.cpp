#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int item;
  Node* next;
};


class StackList{
  private: Node* top;
  public: StackList(): top(nullptr){}

  bool isEmpty(){
    return top == nullptr;
  }
  void push(int data){
    Node* newNode = new Node();
    newNode->item = data;
    newNode->next = top;
    top = newNode;
  }
  int pop(){
    if(isEmpty()){
      return -1;
    }
    Node* temp = top->next;
    int num = top->item;
    delete top;
    top = temp;
    return num;
  }
  int peek(){
    if(isEmpty()){
      return -1;
    }
    return top->item;
  }
  void display(){
    if(isEmpty()){
      cout << "UnderFlow " << endl;
    }
    Node* current = top;
    while(current != nullptr){
      cout << current->item << " ";
      current = current->next;
    }
    cout << endl;
  }
};







int main(){

  StackList list;
  cout << list.isEmpty();
  cout << endl;
  list.push(1);
  list.push(2);
  list.push(3);
  list.push(4);
  list.push(5);
  list.push(6);
  list.push(7);
  list.display();
  int popped = list.pop();
  cout << "Popped: " << popped <<endl;
  list.display();
  cout << "Peek: " << list.peek() << endl;
  list.display();



return 0;
}