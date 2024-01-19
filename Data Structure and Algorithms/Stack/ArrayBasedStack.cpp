#include <iostream>
#include <stack>
using namespace std;

class Stack {
  int top;
  int max_size;
  int* stack;

public:
  void initialize(int Max_size) {
    top = -1;
    stack = new int[Max_size];
    max_size = Max_size;
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == max_size - 1;
  }

  void push(int data) {
    if (isFull()) {
      cout << "Overflow occurred. Cannot push " << data << " onto the stack." << endl;
      return;
    }
    top++;
    stack[top] = data;
    cout << data << " is added to the stack." << endl;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Underflow occurred. Stack is empty." << endl;
      return -1;
    }
    return stack[top--];
  }

  int peek() {
    if (isEmpty()) {
      cout << "Underflow occurred. Stack is empty." << endl;
      return -1;
    }
    return stack[top];
  }

  void print() {
    cout << endl;
    if (isEmpty()) {
      cout << "No elements to display." << endl;
      return;
    }
    for (int i = top; i >= 0; i--) {
      cout << stack[i] << endl;
    }
    cout << endl;
  }

  int size() {
    return top + 1;
  }

  void clear() {
    top = -1;
  }
  int search(int target) {
    if (isEmpty()) {
      return -1;
    }
    for (int i = top; i >= 0; i--) {
      if (stack[i] == target) {
        return i;
      }
    }
    return -1;
  }

  Stack copy() {
    Stack s;
    s.initialize(max_size);
    s.top = top;
    for (int i = 0; i <= top; i++) {
      s.stack[i] = stack[i];
    }
    return s;
  }
  
  static Stack concatenate(Stack stack1, Stack stack2) {
    Stack merged;
    merged.initialize(stack1.max_size + stack2.max_size);
    int temp1 = 0;
    int temp2 = 0;
    while (temp1 <= stack1.top || temp2 <= stack2.top) {
      if (temp1 <= stack1.top) {
        merged.push(stack1.stack[temp1]);
        temp1++;
      } else if (temp2 <= stack2.top) {
        merged.push(stack2.stack[temp2]);
        temp2++;
      }
    }
    return merged;
  }

   int count(int element) {
    int count = 0;
    for (int i = 0; i <= top; ++i) {
      if (stack[i] == element) {
        ++count;
      }
    }
    return count;
  }

  int find_min() {
    if (isEmpty()) {
      cout << "Stack is empty.\n";
      return -1;
    }

    int min_element = stack[0];
    for (int i = 1; i <= top; ++i) {
      if (stack[i] < min_element) {
        min_element = stack[i];
      }
    }
    return min_element;
  }

  int find_max() {
    if (isEmpty()) {
      cout << "Stack is empty.\n";
      return -1; 
    }

    int max_element = stack[0];
    for (int i = 1; i <= top; ++i) {
      if (stack[i] > max_element) {
        max_element = stack[i];
      }
    }
    return max_element;
  }

  bool is_subset(const Stack& other) {
    for (int i = 0; i <= other.top; ++i) {
      bool found = false;
      for (int j = 0; j <= top; ++j) {
        if (other.stack[i] == stack[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        return false; 
      }
    }
    return true; 
  }

  Stack intersection(const Stack& other) {
    Stack result;
    for (int i = 0; i <= top; ++i) {
      for (int j = 0; j <= other.top; ++j) {
        if (stack[i] == other.stack[j]) {
          result.push(stack[i]);
          break;
        }
      }
    }
    return result;
  }

  Stack difference(const Stack& other) {
    Stack result;
    for (int i = 0; i <= top; ++i) {
      bool found = false;
      for (int j = 0; j <= other.top; ++j) {
        if (stack[i] == other.stack[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        result.push(stack[i]);
      }
    }
    for (int i = 0; i <= other.top; ++i) {
      bool found = false;
      for (int j = 0; j <= top; ++j) {
        if (other.stack[i] == stack[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        result.push(other.stack[i]);
      }
    }
    return result;
  }

  void swap_top() {
    if (top >= 1) {
      int temp = stack[top];
      stack[top] = stack[top - 1];
      stack[top - 1] = temp;
    } else {
      cout << "Stack has less than two elements. Unable to swap.\n";
    }
  }

};
int main() {
  Stack s1, s2;
  
  s1.initialize(10);
  s2.initialize(5);

  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);

  cout << "Stack 1:" << endl;
  s1.print();

  
  
  int poppedElement = s1.pop();
  cout << "Popped element: " << poppedElement << endl;

  
    int topElement = s1.peek();
  cout << "Top element: " << topElement << endl;


  int searchResult = s1.search(20);
  cout << "Element 20 is found at index " << searchResult << endl;

  
Stack s1Copy = s1.copy();
  cout << "Copy of Stack 1:" << endl;
  s1Copy.print();

  s2.push(50);
  s2.push(60);

  cout << "Stack 2:" << endl;
  s2.print();

  Stack concatenatedStack = Stack::concatenate(s1, s2);
  cout << "Concatenated Stack:" << endl;
  concatenatedStack.print();

  int countResult = s1.count(30);
  cout << "Element 30 occurs " << countResult << " times in Stack 1." << endl;

  int minElement = s1.find_min();
  int maxElement = s1.find_max();
  cout << "Minimum element in Stack 1: " << minElement << endl;
  cout << "Maximum element in Stack 1: " << maxElement << endl;

  bool isSubset = s1.is_subset(s2);
  cout << "Is Stack 2 a subset of Stack 1? " << (isSubset ? "Yes" : "No") << endl;

  Stack intersectionStack = s1.intersection(s2);
  cout << "Intersection of Stack 1 and Stack 2:" << endl;
  intersectionStack.print();

  Stack differenceStack = s1.difference(s2);
  cout << "Difference between Stack 1 and Stack 2:" << endl;
  differenceStack.print();

  s1.swap_top();
  cout << "After swapping top two elements of Stack 1:" << endl;
  s1.print();

  return 0;
}
