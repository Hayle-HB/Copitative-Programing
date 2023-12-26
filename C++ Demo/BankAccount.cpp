#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <string>

// Structure to represent an account
struct BankAccount {
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
};

#endif // BANKACCOUNT_H
// Function to create a new account and save it to a file
void createAccount(std::vector<BankAccount>& accounts) {
    BankAccount account;
    std::cout << "\033[1;36mEnter account number: \033[0m";
    std::cin >> account.accountNumber;

    // Input control: Check for duplicate account numbers
    for (const BankAccount& acc : accounts) {
        if (acc.accountNumber == account.accountNumber) {
            std::cerr << "\033[1;31mAccount number already exists. Please enter a unique account number.\033[0m" << std::endl;
            return;
        }
    }

    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "\033[1;36mEnter account holder's name: \033[0m";
    std::getline(std::cin, account.accountHolderName);

    // Input control: Ensure the balance is positive
    do {
        std::cout << "\033[1;36mEnter initial balance (must be positive): \033[0m";
        std::cin >> account.balance;

        if (account.balance <= 0.0) {
            std::cerr << "\033[1;31mInvalid initial balance. Please enter a positive amount.\033[0m" << std::endl;
        }
    } while (account.balance <= 0.0);

    // Open the accounts file for appending
    std::ofstream outFile("accounts.txt", std::ios::app);

    if (!outFile) {
        std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
        return;
    }

    // Save the new account to the file
    outFile << account.accountNumber << "," << account.accountHolderName << "," << account.balance << std::endl;
    outFile.close();

    accounts.push_back(account);
    std::cout << "\033[1;32mAccount created successfully.\033[0m" << std::endl;
}

// Function to deposit money into an account
void depositMoney(std::vector<BankAccount>& accounts) {
    std::string accountNumber;
    double amount;

    std::cout << "\033[1;36mEnter account number: \033[0m";
    std::cin >> accountNumber;

    for (BankAccount& account : accounts) {
        if (account.accountNumber == accountNumber) {
            std::cout << "\033[1;36mEnter the amount to deposit (must be positive): \033[0m";
            std::cin >> amount;

            if (amount <= 0.0) {
                std::cerr << "\033[1;31mInvalid deposit amount. Please enter a positive amount.\033[0m" << std::endl;
                return;
            }

            account.balance += amount;

            // Open the accounts file for updating
            std::fstream file("accounts.txt", std::ios::in | std::ios::out);

            if (!file) {
                std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
                return;
            }

            // Update the balance in the file
            std::string line;
            std::streampos pos = 0;

            while (std::getline(file, line)) {
                std::vector<std::string> tokens;
                std::string token;

                // Split the line into tokens using ',' as a delimiter
                std::istringstream ss(line);

                while (std::getline(ss, token, ',')) {
                    tokens.push_back(token);
                }

                if (tokens.size() >= 3 && tokens[0] == accountNumber) {
                    // Update the balance
                    tokens[2] = std::to_string(account.balance);

                    // Seek to the beginning of the line
                    file.seekp(pos, std::ios::beg);

                    // Write the updated line back to the file
                    for (size_t i = 0; i < tokens.size(); ++i) {
                        file << tokens[i];

                        // Add a comma after each token except the last one
                        if (i < tokens.size() - 1) {
                            file << ',';
                        }
                    }

                    // Move to the next line
                    file << std::endl;
                    file.close();

                    std::cout << "\033[1;32mDeposit successful. New balance: " << account.balance << "\033[0m" << std::endl;
                    return;
                }

                // Save the current position for the next iteration
                pos = file.tellg();
            }

            file.close();
            return;
        }
    }

    std::cerr << "\033[1;31mAccount not found.\033[0m" << std::endl;
}


// Function to withdraw money from an account
void withdrawMoney(std::vector<BankAccount>& accounts) {
    std::string accountNumber;
    double amount;

    std::cout << "\033[1;36mEnter account number: \033[0m";
    std::cin >> accountNumber;

    for (BankAccount& account : accounts) {
        if (account.accountNumber == accountNumber) {
            std::cout << "\033[1;36mEnter the amount to withdraw (must be positive): \033[0m";
            std::cin >> amount;

            if (amount <= 0.0) {
                std::cerr << "\033[1;31mInvalid withdrawal amount. Please enter a positive amount.\033[0m" << std::endl;
                return;
            }

            if (account.balance >= amount) {
                account.balance -= amount;

                // Open the accounts file for updating
                std::fstream file("accounts.txt", std::ios::in | std::ios::out);

                if (!file) {
                    std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
                    return;
                }

                // Update the balance in the file
                std::string line;
                std::streampos pos = 0;

                while (std::getline(file, line)) {
                    std::vector<std::string> tokens;
                    std::string token;

                    // Split the line into tokens using ',' as a delimiter
                    std::istringstream ss(line);

                    while (std::getline(ss, token, ',')) {
                        tokens.push_back(token);
                    }

                    if (tokens.size() >= 3 && tokens[0] == accountNumber) {
                        // Update the balance
                        tokens[2] = std::to_string(account.balance);

                        // Seek to the beginning of the line
                        file.seekp(pos, std::ios::beg);

                        // Write the updated line back to the file
                        for (size_t i = 0; i < tokens.size(); ++i) {
                            file << tokens[i];

                            // Add a comma after each token except the last one
                            if (i < tokens.size() - 1) {
                                file << ',';
                            }
                        }

                        // Move to the next line
                        file << std::endl;
                        file.close();

                        std::cout << "\033[1;32mWithdrawal successful. New balance: " << account.balance << "\033[0m" << std::endl;
                        return;
                    }

                    // Save the current position for the next iteration
                    pos = file.tellg();
                }

                file.close();
                return;
            } else {
                std::cerr << "\033[1;31mInsufficient balance to make the withdrawal.\033[0m" << std::endl;
            }

            return;
        }
    }

    std::cerr << "\033[1;31mAccount not found.\033[0m" << std::endl;
}

// Function to transfer money from one account to another
void transferMoney(std::vector<BankAccount>& accounts) {
    std::string senderAccountNumber, receiverAccountNumber;
    double amount;

    std::cout << "\033[1;36mEnter sender's account number: \033[0m";
    std::cin >> senderAccountNumber;
    std::cout << "\033[1;36mEnter receiver's account number: \033[0m";
    std::cin >> receiverAccountNumber;

    BankAccount* senderAccount = nullptr;
    BankAccount* receiverAccount = nullptr;

    // Find the sender and receiver accounts
    for (BankAccount& account : accounts) {
        if (account.accountNumber == senderAccountNumber) {
            senderAccount = &account;
        } else if (account.accountNumber == receiverAccountNumber) {
            receiverAccount = &account;
        }

        // Exit the loop if both sender and receiver accounts are found
        if (senderAccount && receiverAccount) {
            break;
        }
    }

    if (!senderAccount) {
        std::cerr << "\033[1;31mSender's account not found.\033[0m" << std::endl;
        return;
    }

    if (!receiverAccount) {
        std::cerr << "\033[1;31mReceiver's account not found.\033[0m" << std::endl;
        return;
    }

    std::cout << "\033[1;36mEnter the amount to transfer (must be positive): \033[0m";
    std::cin >> amount;

    if (amount <= 0.0) {
        std::cerr << "\033[1;31mInvalid transfer amount. Please enter a positive amount.\033[0m" << std::endl;
        return;
    }

    if (senderAccount->balance >= amount) {
        senderAccount->balance -= amount;
        receiverAccount->balance += amount;

        // Open the accounts file for updating
        std::fstream file("accounts.txt", std::ios::in | std::ios::out);

        if (!file) {
            std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
            return;
        }

        // Update the balances in the file
        std::string line;
        std::streampos pos = 0;

        while (std::getline(file, line)) {
            std::vector<std::string> tokens;
            std::string token;

            // Split the line into tokens using ',' as a delimiter
            std::istringstream ss(line);

            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 3) {
                if (tokens[0] == senderAccountNumber) {
                    // Update the sender's balance
                    tokens[2] = std::to_string(senderAccount->balance);
                } else if (tokens[0] == receiverAccountNumber) {
                    // Update the receiver's balance
                    tokens[2] = std::to_string(receiverAccount->balance);
                }

                // Seek to the beginning of the line
                file.seekp(pos, std::ios::beg);

                // Write the updated line back to the file
                for (size_t i = 0; i < tokens.size(); ++i) {
                    file << tokens[i];

                    // Add a comma after each token except the last one
                    if (i < tokens.size() - 1) {
                        file << ',';
                    }
                }

                // Move to the next line
                file << std::endl;
            }

            // Save the current position for the next iteration
            pos = file.tellg();
        }

        file.close();

        std::cout << "\033[1;32mTransfer successful. New balance for sender: " << senderAccount->balance << "\033[0m" << std::endl;
        std::cout << "\033[1;32mNew balance for receiver: " << receiverAccount->balance << "\033[0m" << std::endl;
    } else {
        std::cerr << "\033[1;31mInsufficient balance in the sender's account to make the transfer.\033[0m" << std::endl;
    }
}


// Function to calculate and add interest money to all accounts
void calculateInterest(std::vector<BankAccount>& accounts, double interestRate) {
    if (interestRate <= 0.0) {
        std::cerr << "\033[1;31mInvalid interest rate. Please enter a positive rate.\033[0m" << std::endl;
        return;
    }

    for (BankAccount& account : accounts) {
        double interestAmount = account.balance * (interestRate / 100.0);
        account.balance += interestAmount;

        // Open the accounts file for updating
        std::fstream file("accounts.txt", std::ios::in | std::ios::out);

        if (!file) {
            std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
            return;
        }

        // Update the balance in the file
        std::string line;
        std::streampos pos = 0;

        while (std::getline(file, line)) {
            std::vector<std::string> tokens;
            std::string token;

            // Split the line into tokens using ',' as a delimiter
            std::istringstream ss(line);

            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 3 && tokens[0] == account.accountNumber) {
                // Update the balance
                tokens[2] = std::to_string(account.balance);

                // Seek to the beginning of the line
                file.seekp(pos, std::ios::beg);

                // Write the updated line back to the file
                for (size_t i = 0; i < tokens.size(); ++i) {
                    file << tokens[i];

                    // Add a comma after each token except the last one
                    if (i < tokens.size() - 1) {
                        file << ',';
                    }
                }

                // Move to the next line
                file << std::endl;
            }

            // Save the current position for the next iteration
            pos = file.tellg();
        }

        file.close();
    }

    std::cout << "\033[1;32mInterest calculated and added to all accounts.\033[0m" << std::endl;
}

// Function to display transaction history for a given account
void displayTransactionHistory(const std::string& accountNumber) {
    std::ifstream inFile("accounts.txt");

    if (!inFile) {
        std::cerr << "\033[1;31mError opening the accounts file!\033[0m" << std::endl;
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        // Split the line into tokens using ',' as a delimiter
        std::istringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 3 && tokens[0] == accountNumber) {
            found = true;
            std::cout << "\033[1;32mTransaction history for account " << tokens[0] << " (Holder: " << tokens[1] << "):\033[0m" << std::endl;
            std::cout << "\033[1;32mBalance: " << tokens[2] << "\033[0m" << std::endl;
        }
    }

    inFile.close();

    if (!found) {
        std::cerr << "\033[1;31mAccount not found.\033[0m" << std::endl;
    }
}


int main() {
    std::vector<BankAccount> accounts;
    double interestRate;
    std::string accountNumber;

    std::cout << "\033[1;34mWelcome to the Bank Management System!\033[0m" << std::endl;

    while (true) {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "\033[1;36m1. Create Account\033[0m" << std::endl;
        std::cout << "\033[1;36m2. Deposit Money\033[0m" << std::endl;
        std::cout << "\033[1;36m3. Withdraw Money\033[0m" << std::endl;
        std::cout << "\033[1;36m4. Transfer Money\033[0m" << std::endl;
        std::cout << "\033[1;36m5. Calculate Interest\033[0m" << std::endl;
        std::cout << "\033[1;36m6. Display Transaction History\033[0m" << std::endl;
        std::cout << "\033[1;36m7. Exit\033[0m" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "\033[1;36mSelect an option: \033[0m";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear newline characters from the input buffer

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositMoney(accounts);
                break;
            case 3:
                withdrawMoney(accounts);
                break;
            case 4:
                transferMoney(accounts);
                break;
            case 5:
                std::cout << "\033[1;36mEnter interest rate (%): \033[0m";
                std::cin >> interestRate;
                calculateInterest(accounts, interestRate);
                break;
            case 6:
                std::cout << "\033[1;36mEnter account number: \033[0m";
                std::cin.ignore(); // Clear newline characters from the input buffer
                std::getline(std::cin, accountNumber);
                displayTransactionHistory(accountNumber);
                break;
            case 7:
                std::cout << "\033[1;34mExiting the program. Goodbye!\033[0m" << std::endl;
                return 0;
            default:
                std::cerr << "\033[1;31mInvalid choice. Please select a valid option.\033[0m" << std::endl;
                break;
        }
    }

    return 0;
}
