/*Write a C++ program that permits users to enter the following information about
your small company’s 10 employees, sorts the information in ascending ID
number, and then writes the sorted information to a file:
ID No. Sex(M/F) Hourly-Wage Years-with-the-Company
After the records are stored successfully,
(a) write a program that reads the file created one record at a time, asks for the
number of hours each employee worked each month, and calculates and
displays each employee’s total pay for the month
(b) Develop a program that reads the file created and changes the hourly wage or
years for each employee, and creates a new updated file*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 2;

struct Employee {
    int id;
    char sex;
    double hourlyWage;
    int yearsWithCompany;
};

// Function to get employee information from user
void getEmployeeInfo(Employee &employee) {
    cout << "Enter Employee ID: ";
    cin >> employee.id;
    cout << "Enter Employee Sex (M/F): ";
    cin >> employee.sex;
    cout << "Enter Hourly Wage: ";
    cin >> employee.hourlyWage;
    cout << "Enter Years with the Company: ";
    cin >> employee.yearsWithCompany;
}

// Function to calculate total pay for a month
double calculateTotalPay(const Employee &employee, double hoursWorked) {
    return employee.hourlyWage * hoursWorked;
}

// Function to display employee information
void displayEmployeeInfo(const Employee &employee) {
    cout << "Employee ID: " << employee.id << endl;
    cout << "Sex: " << employee.sex << endl;
    cout << "Hourly Wage: " << employee.hourlyWage << endl;
    cout << "Years with the Company: " << employee.yearsWithCompany << endl;
}

int main() {
    Employee employees[MAX_EMPLOYEES];

    // Get employee information
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        getEmployeeInfo(employees[i]);
    }

    // Sort employees by ID manually using bubble sort
    for (int i = 0; i < MAX_EMPLOYEES - 1; i++) {
        for (int j = 0; j < MAX_EMPLOYEES - i - 1; j++) {
            if (employees[j].id > employees[j + 1].id) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    // Write sorted employee information to a file
    ofstream outFile("employee_records.txt");
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        outFile << employees[i].id << " " << employees[i].sex << " " << employees[i].hourlyWage << " " << employees[i].yearsWithCompany << endl;
    }

    outFile.close();
    cout << "Employee records saved successfully." << endl;

    int option;
    double hoursWorked;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Calculate Total Pay for a Month" << endl;
        cout << "2. Update Employee Information" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            int employeeID;
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cout << "Enter Hours Worked for the Month: ";
            cin >> hoursWorked;

            ifstream inFile("employee_records.txt");
            if (!inFile) {
                cerr << "Error opening file for reading." << endl;
                return 1;
            }

            Employee employee;
            bool found = false;

            while (inFile >> employee.id >> employee.sex >> employee.hourlyWage >> employee.yearsWithCompany) {
                if (employee.id == employeeID) {
                    double totalPay = calculateTotalPay(employee, hoursWorked);
                    displayEmployeeInfo(employee);
                    cout << "Total Pay for the Month: " << totalPay << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Employee not found." << endl;
            }

            inFile.close();
        } else if (option == 2) {
            int employeeID;
            cout << "Enter Employee ID to Update: ";
            cin >> employeeID;

            ifstream inFile("employee_records.txt");
            if (!inFile) {
                cerr << "Error opening file for reading." << endl;
                return 1;
            }

            Employee updatedEmployees[MAX_EMPLOYEES];
            int index = 0;
            bool found = false;

            while (inFile >> updatedEmployees[index].id >> updatedEmployees[index].sex >> updatedEmployees[index].hourlyWage >> updatedEmployees[index].yearsWithCompany) {
                if (updatedEmployees[index].id == employeeID) {
                    getEmployeeInfo(updatedEmployees[index]);
                    found = true;
                }
                index++;
            }

            if (!found) {
                cout << "Employee not found." << endl;
            }

            inFile.close();

            // Write the updated employee information to a new file
            ofstream updatedFile("updated_employee_records.txt");
            if (!updatedFile) {
                cerr << "Error opening file for writing." << endl;
                return 1;
            }

            for (int i = 0; i < index; i++) {
                updatedFile << updatedEmployees[i].id << " " << updatedEmployees[i].sex << " " << updatedEmployees[i].hourlyWage << " " << updatedEmployees[i].yearsWithCompany << endl;
            }

            updatedFile.close();
            cout << "Employee information updated successfully." << endl;
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
