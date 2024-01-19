#include <iostream>
#include <string>
using namespace std;

// Node structure for a student
struct Node {
    string Name;
    string ID;
    int Age;
    string Department;
    Node* next;
};

// StudentList class to manage the linked list
class StudentList {
private:
    Node* head;

public:
    StudentList() : head(nullptr) {}

    void addStudentFromKeyboard(string name, string ID, int age, string department, string position) {
        Node* newNode = new Node();
        newNode->Name = name;
        newNode->ID = ID;
        newNode->Age = age;
        newNode->Department = department;

        if (position == "front") {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (position == "middle") {
                    newNode->next = current->next;
                    current->next = newNode;
                    break;
                } else if (position == "last" && current->next->next == nullptr) {
                    current->next->next = newNode;
                    newNode->next = nullptr;
                    break;
                }
                current = current->next;
            }
        }
    }

    void deleteNode(string position) {
        if (head == nullptr) {
            cout << "No element is found to be deleted." << endl;
            return;
        }

        if (position == "first") {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else if (position == "last") {
            Node* current = head;
            Node* prev = nullptr;

            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            delete current;

            if (prev != nullptr) {
                prev->next = nullptr;
            } else {
                head = nullptr;  // If there was only one node
            }
        } else if (position == "middle") {
            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            Node* temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "No element is found." << endl;
            return;
        }

        Node* current = head;
        int k = 1;

        while (current != nullptr) {
            cout << "*********  Student " << k << "********\n"
                 << "Name:  " << current->Name << endl
                 << "ID:  " << current->ID << endl
                 << "AGE:  " << current->Age << endl
                 << "Department:  " << current->Department << endl
                 << "********************************************\n";

            k++;
            current = current->next;
        }

        cout << endl << endl;
    }

    Node* searchNode(string name) {
        Node* current = head;

        while (current != nullptr) {
            if (current->Name == name) {
                return current;
            }
            current = current->next;
        }

        return nullptr;  // Node not found
    }
};
// ...

int main() {
    StudentList studentList;

    int choice;
    string name, ID, department;
    int age;
    string position;

    do {
        cout << "Menu:\n";
        cout << "1. Add a new student data\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the whole list of students\n";
        cout << "4. Search a specific node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter student details:\n";
                cout << "Name: ";
                cin >> name;
                cout << "ID: ";
                cin >> ID;
                cout << "Age: ";
                cin >> age;
                cout << "Department: ";
                cin >> department;
                cout << "Enter position (front, middle, last): ";
                cin >> position;
                studentList.addStudentFromKeyboard(name, ID, age, department, position);
            }
            break;

            case 2: {
                cout << "Enter position to delete (first, last, middle): ";
                cin >> position;
                studentList.deleteNode(position);
                break;
            }

            case 3:
                studentList.display();
                break;

            case 4: {
                cout << "Enter student name to search: ";
                cin >> name;
                Node* foundNode = studentList.searchNode(name);
                if (foundNode != nullptr) {
                    cout << "Student found:\n";
                    cout << "Name: " << foundNode->Name << endl;
                    cout << "ID: " << foundNode->ID << endl;
                    cout << "Age: " << foundNode->Age << endl;
                    cout << "Department: " << foundNode->Department << endl;
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
