#include <iostream>
#include <stack>
using namespace std;

struct Node{
  int data;
  Node* next;
};

struct LinkedList {
  private: Node* head;
  public: 
  LinkedList(): head(nullptr){}
  void insertAtFirst(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
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
  
  void insertAtEnd(int data){
    Node* newNode  = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    Node* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = newNode;
  }
  
  void insertAtPosition(int data, int position){
    if( position < 1){ cout<< "Invalid position " << endl; return;}
    if( position == 1){ insertAtFirst(data); return; }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    Node* current = head;
    Node* prev = nullptr;
    for (int i =1; i < position && current != nullptr ; i++){
        prev  = current;
        current = current->next;
    }
    if(current == nullptr){
      cout << "Invalid position" << endl;
      return;
    }
    prev->next = newNode;
    newNode->next = current;
  }
  void deleteAtFirst(){
    Node* temp = head->next;
    delete head;
    head = temp;
  }
  
  void deleteAtPosition(int pos){
    if(pos == 1){
      deleteAtFirst();
      return;
    }
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    
    for(int i = 1; i < pos && current != nullptr; ++i){
        prev = current;
        current = current->next;
        next = current->next;
    }
    prev->next = next;
    delete current;
  }
  void deleteAtEnd(){
   Node* current = head;
   Node* prev = nullptr;
   while(current->next != nullptr){
      prev = current;
      current = current->next;
    }
      prev->next = nullptr;
      delete current;
  }
int deleteElement(int data) {
    Node* current = head;
    Node* prev = nullptr;

    if (head == nullptr) {
        return -1; // no element is found to delete 
    }

    if (head->data == data) {
        deleteAtFirst();
        return 1;
    }

    prev = head;
    current = current->next;

    while (current != nullptr) {
        if (current->data == data) {
            prev->next = current->next;
            delete current;
            return 1;
        }
        prev = current;
        current = current->next;
    }

    return -1;
} 
  int searchNode(int data){
    if(head == nullptr){
      return -1;
    }
    Node* current = head;
    int index = 1;
    while(current != nullptr){
      if(current->data == data){
        return index;
      }
      index++;
      current = current->next;
    }
    return -1;

  }
  void sortNode(){
    Node* current = head;
    Node* rot = nullptr;
    while(current != nullptr){
      rot = current->next;
      while(rot != nullptr){
        if(current->data > rot->data){
          int temp = current->data;
          current->data = rot->data;
          rot->data = temp;
        }
        rot = rot->next;
      }
      current = current->next;
    }
  }
  void reverseNode(){
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(current != nullptr){
      next = current->next;
      current->next = prev;

      prev = current;
      current = next;
    }
    head = prev;
  }
  bool isPalindrome(){
  Node* fast = head;
  Node* slow = head;
  stack<int> s;
  while(fast && fast->next){
    s.push(slow->data);
    slow = slow->next;
    fast = fast->next->next;
  }  
  if(fast){
    slow = slow->next;
  }
  while(slow){
    if( s.top() != slow->data){
      return false;
    }
    s.pop();
    slow = slow->next;
  }
  return true;

 }
void mergeSortedLists(const LinkedList& list1, const LinkedList& list2) {
    // Clear the current list before merging
    this->~LinkedList();

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
            if (current1->data < current2->data) {
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

  
  bool isPilndromeOne(){
    Node* current = head;
    long long Number = 0;
    long long exp = 1;
    while( current != nullptr){
      Number += current->data * exp;
      exp *= 10;
      current = current->next;
    }
    string str = to_string(Number);
    for(int i =0; i < str.length()/2; i++){
      if(str[i] != str[str.length()-i-1]){
          return false;
      }
    }
    return true;
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

LinkedList reverseNode(LinkedList list){
  LinkedList answer;
  list.reverseNode();
  answer = list;
  return answer;
}




int main() {
    LinkedList myList;

    int choice;
    int data, position;

    do {
        cout << "************ MENU ************" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete at Beginning" << endl;
        cout << "5. Delete at Position" << endl;
        cout << "6. Delete at End" << endl;
        cout << "7. Delete by Data" << endl;
        cout << "8. Search Node" << endl;
        cout << "9. Sort Nodes" << endl;
        cout << "10. Reverse Nodes" << endl;
        cout << "11. Check Palindrome" << endl;
        cout << "12. Display" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                myList.insertAtFirst(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                myList.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                myList.insertAtPosition(data, position);
                break;
            case 4:
                myList.deleteAtFirst();
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                myList.deleteAtPosition(position);
                break;
            case 6:
                myList.deleteAtEnd();
                break;
            case 7:
                cout << "Enter data to delete: ";
                cin >> data;
                myList.deleteElement(data);
                break;
            case 8:
                cout << "Enter data to search: ";
                cin >> data;
                position = myList.searchNode(data);
                if (position != -1)
                    cout << "Node found at position: " << position << endl;
                else
                    cout << "Node not found." << endl;
                break;
            case 9:
                myList.sortNode();
                cout << "List sorted." << endl;
                break;
            case 10:
                myList.reverseNode();
                cout << "List reversed." << endl;
                break;
            case 11:
                if (myList.isPalindrome())
                    cout << "The linked list is a palindrome." << endl;
                else
                    cout << "The linked list is not a palindrome." << endl;
                break;
            case 12:
                myList.display();
                break;
            case 13:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 13);

    return 0;
}
