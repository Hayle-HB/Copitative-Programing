#include <iostream>
using namespace std;


struct Queue {
  int Max_size;
  int* QueueList;
  int front;
  int back;
};


void initialize(Queue& queue, int Max_size){
  queue.QueueList = new int[Max_size];
  queue.Max_size = Max_size;
  queue.front = -1;
  queue.back = -1;
  
}
bool isEmpty(const Queue& queue){
  return queue.back == -1;
}
bool isFull(const Queue& queue){
  return queue.back == queue.Max_size-1;
}
void enqueue(Queue& queue, int data){
  if(isFull(queue)){
    cout << "Queue OverFlow: " << endl;
    return;
  }

  if( queue.back == -1){
      queue.back = queue.front = 0;
      queue.QueueList[queue.front] = data;
      cout << "The first Element is Successfully Entered" << endl;
      return;
  }
  queue.back++;
  queue.QueueList[queue.back] = data;
  cout << "Data stored Successfully " << endl;
}
int dequeue(Queue& que){
  if(isEmpty(que)){
    cerr << "Queue UnderFlow " << endl;
  }

  int dequeue = que.QueueList[que.front];
  que.front++;
  return dequeue;
}
int peek(const Queue& que){
  return que.QueueList[que.front];
}
void display(const Queue& que){
  if(isEmpty(que)){
    cout << "No Element is found in this Queue " << endl;
    return;
  }
  for(int i = que.front; i <= que.back; i++){
    cout << que.QueueList[i] << " " ;
  }
  cout << endl;
}

int main(){


  Queue que;
  initialize(que, 10);
 if(isEmpty(que))
   cout << "There is no Data in the Queue " << endl;
  enqueue(que, 1);
  enqueue(que, 2);
  enqueue(que, 3);
  enqueue(que, 4);
  enqueue(que, 5);
  enqueue(que, 6);
  display(que);
  cout << "Dequeue: " << dequeue(que) << endl;
  display(que);
  cout << "Peeked: " << peek(que) << endl;






  return 0;
}