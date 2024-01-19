#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int item): data(item), next(nullptr){}
};
    ListNode* head = nullptr;

bool is_a_Cycle_In_the_linkedList(){
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        if(slow == fast){
        return true;
        }
    }
    return false;
}


int main(){
    
    ListNode* first =  new ListNode(1);
    ListNode* second = new ListNode(3);
    ListNode* third =  new ListNode(4);
    ListNode* fourth = new ListNode(5);
    ListNode* five =  new ListNode(6);
    ListNode* sixth = new ListNode(7);
    head = first;
    
    first->next = second;
    second -> next = third;
    third->next = fourth;
    fourth->next = five;
    five->next = sixth;
    sixth->next = first;
    
    if(is_a_Cycle_In_the_linkedList()){
        cout << "Yes, There is a Cycle " <<endl;
        }
    else {
    cout << "No, There is not a Cycle in the List " << endl;
    }
    
    
    delete first;
    delete second;
    delete third;
    delete five;
    delete sixth;
    

  return 0;
}