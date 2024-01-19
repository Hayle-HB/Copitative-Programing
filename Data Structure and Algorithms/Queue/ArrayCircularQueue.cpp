#include <iostream>
using namespace std;

struct Queue{
  int* QueueList;
  int Max_size;
  int front;
  int back;
  Queue(){
    this->back = -1;
    this->front = -1;
  }
};
class QueueArray {
  private: 
   Queue que;
   int QueSize;
   public:
   QueueArray(): que(), QueSize(0){}
  void initialize(int max){
    que.Max_size = max;
    que.QueueList = new int[max];
    Queue();
  }
   bool isEmpty() {
    return que.front == -1;
   }
   bool isFull(){
    return QueSize - que.front  == que.Max_size - 1;
  }
   void enqueue(int data){
    if(isFull()){
      cout << "Queue OverFlow " << endl;
      return; 
    }
    if(que.back == -1){
      que.back = que.front = 0;
      que.QueueList[que.back] = data;
      QueSize++;
      return;
    }
   
    que.back++;
    if(que.back == que.Max_size - 1){
      que.back = 0;
    }
    que.QueueList[que.back] = data;

   }
   int dequeue(){
    if(isEmpty()){
      cout << "Queue UnderFlow" << endl;
    }

    int deq = que.QueueList[que.front];
    que.front++;
    return deq;
   }
   

   void display(){
    cout << endl;
    if(isEmpty()){
      cout << "No Element is found in the Queue list " << endl;
      return;
    }

    if( que.front > que.back){
      for(int i =0; i < que.Max_size -1 ; i++){
        cout << que.QueueList[i] << "  ";
      }
      for(int i =0; i < que.front; i++){
        cout << que.QueueList[i] << "  ";
      }
      return;
    }
    for(int i = que.front; i <= que.back; i++){
      cout << que.QueueList[i] << "  ";
    }





   }

};

int main(){


  QueueArray que;
  que.initialize(10);
  cout << que.isEmpty();
  que.enqueue(1);
  cout << que.isEmpty();
  que.enqueue(2);
  que.enqueue(3);
  que.enqueue(4);
  que.enqueue(5);
  que.enqueue(6);
  que.enqueue(7);
  que.enqueue(8);
  que.display();






  return 0;
}