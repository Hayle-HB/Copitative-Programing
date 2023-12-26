#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
    string startDate;
};

void displayRecords() {
    ifstream inFile("emp.txt", ios::in);  
    string line;

    cout << "Employee Records:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

bool deleteRecord(int id) {
    ifstream inFile("emp.txt", ios::in);  
    ofstream outFile("temp.txt", ios::out); 
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        int recordId;
        istringstream iss(line);

        if (iss >> recordId) {
            if (recordId == id) {
                found = true;
                continue; 
            }
        }

        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the temporary file
    remove("emp.txt");
    rename("temp.txt", "emp.txt");

    return found;
}

int main() {
    int choice;
    int idToDelete;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Employee Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Delete Employee Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee emp;
                for(int i =0; i < 5; i++){
                cout << "Enter Employee ID of employee " << i+1 << " : ";
                cin >> emp.id;
                cout << "Enter Name of employee " << i+1 << " : ";
                cin.ignore();
                getline(cin, emp.name);
                cout << "Enter Salary of employee " << i+1 << " : ";
                cin >> emp.salary;
                cout << "Enter Start Date (MM/DD/YYYY) of employee " << i+1 << " : ";
                cin >> emp.startDate;

                ofstream outFile("emp.txt", ios::app | ios::out); 
                outFile << emp.id << " " << emp.name << " " << emp.salary << " " << emp.startDate << endl;
                outFile.close();
                }
                break;
            }

            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Enter the ID of the employee record to delete: ";
                cin >> idToDelete;
                if (deleteRecord(idToDelete)) {
                    cout << "Employee record with ID " << idToDelete << " has been deleted." << endl;
                } else {
                    cout << "Employee record with ID " << idToDelete << " not found." << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
