#include <iostream>
using namespace std;

struct Node{
  string Name;
  string ID;
  int age;
  string department;
  Node* prev;
  Node* next;
};

class StudentList {
  private:
  Node* head;
  Node* tail;
  public:
  StudentList(): head(nullptr), tail(nullptr){} 
  
  void AddStudentRecoded(string name, string ID, int age, string department){
    Node* newNode = new Node();
    newNode->Name = name;
    newNode->ID = ID;
    newNode->age = age;
    newNode->department = department;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(head == nullptr){
      head = tail= newNode;
      cout << "Record Succesfully registered " << endl;
      return;
    }
    int option;
    cout << "Enter your option:\n"
         << "1.at the first, \n" 
         <<" 2. to end, \n "
         << "3. to the middle) ";
    cin >> option;

    if(option == 1 ){
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      cout << "Record Succesfully registered " << endl;
    }
    else if(option == 2){
       tail->next = newNode;
       newNode->prev = tail;
       tail = newNode;
      cout << "Record Succesfully registered " << endl;
    }

    else if(option == 3 ){

    }

    else {
      cout << "Invalid option try later \n";
    }















  }

};


int main(){
  StudentList list;

  string name = "Haile";
  string ID = "ETS0756";
  int age = 21;
  string department = "Software Engineering ";
  list.AddStudentRecoded(name, ID, age, department);
  list.AddStudentRecoded(name, ID, age, department);
  list.AddStudentRecoded(name, ID, age, department);




  return 0;
}