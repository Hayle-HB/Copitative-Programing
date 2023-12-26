#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an account
struct Account {
    int accountNumber;
    string accountName;
    double balance;

    // Constructor
    Account(int number, string name, double initialBalance) {
        accountNumber = number;
        accountName = name;
        balance = initialBalance;
    }
};

// Function to read accounts from a file
vector<Account> readAccountsFromFile() {
    vector<Account> accounts;
    ifstream inFile("accounts.txt");
    int number;
    string name;
    double balance;
    while (inFile >> number >> name >> balance) {
        accounts.push_back(Account(number, name, balance));
    }
    inFile.close();
    return accounts;
}

// Function to write accounts to a file
void writeAccountsToFile(const vector<Account>& accounts) {
    ofstream outFile("accounts.txt");
    for (const Account& account : accounts) {
        outFile << account.accountNumber << " " << account.accountName << " " << account.balance << endl;
    }
    outFile.close();
}

// Function to create a new account
void createAccount(vector<Account>& accounts, int& accountNumberCounter) {
    string accountName;
    double initialBalance;

    cout << "Enter account name: ";
    cin.ignore();
    getline(cin, accountName);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Check if the account number is already used
    bool accountExists = false;
    for (const Account& account : accounts) {
        if (account.accountName == accountName) {
            accountExists = true;
            break;
        }
    }

    if (!accountExists) {
        accounts.push_back(Account(accountNumberCounter++, accountName, initialBalance));
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Account with the same name already exists. Account not created." << endl;
    }
}

// Function to deposit funds
void depositFunds(vector<Account>& accounts) {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Find the account by account number
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const Account& account) {
        return account.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            it->balance += amount;
            cout << "Deposit successful. New balance: " << it->balance << endl;
        } else {
            cout << "Invalid deposit amount. Deposit failed." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

// Function to withdraw funds
void withdrawFunds(vector<Account>& accounts) {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Find the account by account number
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const Account& account) {
        return account.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > 0 && amount <= it->balance) {
            it->balance -= amount;
            cout << "Withdrawal successful. New balance: " << it->balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance. Withdrawal failed." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

// Function to transfer funds from one account to another
void transferFunds(vector<Account>& accounts) {
    int fromAccountNumber, toAccountNumber;
    double amount;

    cout << "Enter source account number: ";
    cin >> fromAccountNumber;

    cout << "Enter destination account number: ";
    cin >> toAccountNumber;

    // Find the source account
    auto fromAccount = find_if(accounts.begin(), accounts.end(), [fromAccountNumber](const Account& account) {
        return account.accountNumber == fromAccountNumber;
    });

    // Find the destination account
    auto toAccount = find_if(accounts.begin(), accounts.end(), [toAccountNumber](const Account& account) {
        return account.accountNumber == toAccountNumber;
    });

    if (fromAccount != accounts.end() && toAccount != accounts.end()) {
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount > 0 && amount <= fromAccount->balance) {
            fromAccount->balance -= amount;
            toAccount->balance += amount;
            cout << "Transfer successful. New balance of source account: " << fromAccount->balance << endl;
            cout << "New balance of destination account: " << toAccount->balance << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance. Transfer failed." << endl;
        }
    } else {
        cout << "One or both accounts not found." << endl;
    }
}

// Function to view transaction history (not implemented in this example)

// Function to calculate interest for all accounts
void calculateInterest(vector<Account>& accounts, double interestRate) {
    for (Account& account : accounts) {
        double interest = (account.balance * interestRate) / 100.0;
        account.balance += interest;
    }
    cout << "Interest calculated and added to all accounts." << endl;
}

// Function to close an account
void closeAccount(vector<Account>& accounts) {
    int accountNumber;

    cout << "Enter account number to close: ";
    cin >> accountNumber;

    // Find the account by account number
    auto it = find_if(accounts.begin(), accounts.end(), [accountNumber](const Account& account) {
        return account.accountNumber == accountNumber;
    });

    if (it != accounts.end()) {
        accounts.erase(it);
        cout << "Account closed successfully." << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

// Function to list all accounts
void listAllAccounts(const vector<Account>& accounts) {
    cout << "List of all accounts:" << endl;
    for (const Account& account : accounts) {
        cout << "Account Number: " << account.accountNumber << " | Account Name: " << account.accountName << " | Balance: " << account.balance << endl;
    }
}

int main() {
    vector<Account> accounts = readAccountsFromFile();
    int accountNumberCounter = 1; // Counter for generating unique account numbers

    while (true) {
        cout << "Banking Application Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Transfer Funds" << endl;
        cout << "5. View Transaction History" << endl;
        cout << "6. Calculate Interest" << endl;
        cout << "7. Close Account" << endl;
        cout << "8. List All Accounts" << endl;
        cout << "9. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 9) {
            writeAccountsToFile(accounts);
            cout << "Exiting the application. Data has been saved to accounts.txt." << endl;
            break;
        }

        switch (choice) {
            case 1:
                createAccount(accounts, accountNumberCounter);
                break;
            case 2:
                depositFunds(accounts);
                break;
            case 3:
                withdrawFunds(accounts);
                break;
            case 4:
                transferFunds(accounts);
                break;
            case 5:
                // View Transaction History (Not implemented in this example)
                cout << "Transaction history feature not implemented." << endl;
                break;
            case 6:
                double interestRate;
                cout << "Enter interest rate: ";
                cin >> interestRate;
                calculateInterest(accounts, interestRate);
                break;
            case 7:
                closeAccount(accounts);
                break;
            case 8:
                listAllAccounts(accounts);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
