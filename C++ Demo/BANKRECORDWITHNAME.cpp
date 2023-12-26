#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Customer {
    int accountNumber;
    string firstName;
    string lastName;
    double balance;
};

void createCustomerFile() {
    ofstream outFile("customer_records.txt");

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    int startingAccountNumber = 1000;

    for (int i = 0; i < 5; i++) {
        Customer customer;
        customer.accountNumber = startingAccountNumber + i;

        cout << "Enter first name for account " << customer.accountNumber << ": ";
        cin >> customer.firstName;
        cout << "Enter last name for account " << customer.accountNumber << ": ";
        cin >> customer.lastName;
        cout << "Enter balance for account " << customer.accountNumber << ": ";
        cin >> customer.balance;

        outFile << customer.accountNumber << " " << customer.firstName << " " << customer.lastName << " " << customer.balance << endl;
    }

    outFile.close();
    cout << "Customer file created successfully." << endl;
}

void displayCustomerInfo(int accountNumberToSearch) {
    ifstream inFile("customer_records.txt");

    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Customer customer;
    bool found = false;

    while (inFile >> customer.accountNumber >> customer.firstName >> customer.lastName >> customer.balance) {
        if (customer.accountNumber == accountNumberToSearch) {
            cout << "Account Number: " << customer.accountNumber << endl;
            cout << "First Name: " << customer.firstName << endl;
            cout << "Last Name: " << customer.lastName << endl;
            cout << "Balance: " << customer.balance << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found." << endl;
    }

    inFile.close();
}

int main() {
    int choice;
    int accountNumberToSearch;

    cout << "Menu:" << endl;
    cout << "1. Create Customer File" << endl;
    cout << "2. Search for Customer by Account Number" << endl;
    cout << "3. Exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createCustomerFile();
                break;
            case 2:
                cout << "Enter the account number to search for: ";
                cin >> accountNumberToSearch;
                displayCustomerInfo(accountNumberToSearch);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
