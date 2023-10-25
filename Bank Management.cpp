#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;


struct BankAccount {
    int accountNumber;
    string name;
    double balance;
};

string Beginner_word_or_char;

struct Loan {
    int loanAccountNumber;
    string loanTakerName;
    string payingDate;
    double paidAmount;
    double amountRemaining;
};

// ANSI color codes for text color 
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string MAGENTA = "\033[1;35m";
const string CYAN = "\033[1;36m";
const string WHITE = "\033[1;37m";
const string BOLD_RED = "\033[1;91m";
const string BOLD_GREEN = "\033[1;92m";
const string BOLD_BLUE = "\033[1;94m";
const string RESET_COLOR = "\033[0m"; // Reset color to default


void BANK_MANAGEMENT();
void createAccount();
void createLoanBook(vector<Loan>& loans);
void createLoanAgreement();
void makeMonthlyRepayment(vector<Loan>& loans);
void displayLoanBook();
void depositFunds();
void withdrawFunds();
void transferFunds();
void viewCurrentBalance();
void calculateAndAddInterest();
void closeAccountWithBalance(int accountNumberToClose);
void listAllAccounts();
double calculateTotalAmountInBank();
void deleteAllAccounts();
string calculateStartPaymentDate();
void display_menu();





int main() {
    BANK_MANAGEMENT();
    system("cls");
    vector<BankAccount> savingsAccounts;
    vector<Loan> loans;

    while (true) {
        cout << "Banking System Menu:" << endl;
        cout << "1. Savings Account" << endl;
        cout << "2. Loan Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
     system("cls");

        if (!cin) {
            // If the input is not valid, clear the error state and consume the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer choice." << endl;
            continue;
        }

        system("cls");

        switch (choice) {
            case 1: // Savings Account
                while (true) {
                    cout << BOLD_GREEN <<  "<Savings Account Menu:" <<  RESET_COLOR << endl;
                    cout << "1. Create Account" << endl;
                    cout << "2. Deposit" << endl;
                    cout << "3. Withdraw" << endl;
                    cout << "4. Transfer Money " << endl;
                    cout << "5. View Current Balance" << endl;
                    cout << "6. Calculate and Add Interest" << endl;
                    cout << "7. Close Account with Balance" << endl;
                    cout << "8. List All Accounts" << endl;
                    cout << "9. Delete All Accounts" << endl;
                    cout << "10 . Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    int savingsChoice;
                    cin >> savingsChoice;
         system("cls");
                    if (!cin) {
                        // If the input is not valid, clear the error state and consume the invalid input
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << "Invalid input. Please enter a valid integer choice." << RESET_COLOR << endl;
                        continue;
                    }

                    system("cls");

                    switch (savingsChoice) {
                        case 1:
                            createAccount();
                            break;
                        case 2:
                            depositFunds();
                            break;
                        case 3:
                            withdrawFunds();
                            break;
                        case 4:
                            transferFunds();
                            break;
                        case 5:
                            viewCurrentBalance();
                            break;
                        case 6:
                            calculateAndAddInterest();
                            break;
                        case 7:
                            int accountNumberToClose;
                            cout << "Enter the account number to close with balance: ";
                            cin >> accountNumberToClose;
                            system("cls");
                            closeAccountWithBalance(accountNumberToClose);
                            break;
                        case 8:
                            listAllAccounts();
                            break;
                        case 9:
                            deleteAllAccounts();
                            break;
                        case 10:
                            break; // Exit the savings menu
                        default:
                            cout << "Invalid choice. Please enter a valid option." << endl;
                    }

                    if (savingsChoice == 10) {
                        break; // Return to the main menu
                    }
                }
                system("cls");
                break;
            case 2: // Loan Account
                while (true) {
                    cout <<BOLD_BLUE << "Loan Account Menu:" << RESET_COLOR <<endl;
                    cout << "1. Create Loan Account" << endl;
                    cout << "2. Create Loan Agreement" << endl;
                    cout << "3. Make Monthly Repayment" << endl;
                    cout << "4. Display Loan Book" << endl;
                    cout << "5. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    int loanChoice;
                    cin >> loanChoice;
            system("cls"); // Clear the screen after input

                    if (!cin) {
                        // If the input is not valid, clear the error state and consume the invalid input
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << "Invalid input. Please enter a valid integer choice." << RESET_COLOR<< endl;
                        continue;
                    }

                    system("cls");

                    switch (loanChoice) {
                        case 1:
                            createLoanBook(loans);
                            break;
                        case 2:
                            createLoanAgreement();
                            break;
                        case 3:
                            makeMonthlyRepayment(loans);
                            break;
                        case 4:
                            displayLoanBook();
                            break;
                        case 5:
                            break; 
                        default:
                            cout << "Invalid choice. Please enter a valid option." << endl;
                    }

                    if (loanChoice == 5) {
                        break; 
                    }
                }
                break;
                
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    system("cls");

    return 0;
}




void createAccount() {
    BankAccount newAccount;
    
    // Input and validate account number (ensure it's unique)
    bool uniqueAccountNumber = false;
    do {
        cout << "Enter Account Number: ";
        cin >> newAccount.accountNumber;
        
        ifstream inputFile("accounts.dat",ios::in);
        uniqueAccountNumber = true;
        
        if (inputFile) {
            BankAccount existingAccount;
            while (inputFile >>  existingAccount.accountNumber >> existingAccount.name >> existingAccount.balance) {
                if (existingAccount.accountNumber == newAccount.accountNumber) {
                        system("cls");
                    cout << RED << "Account number already exists " 
                         << GREEN << " Please choose a different account number." << RESET_COLOR << endl;
                    
                    uniqueAccountNumber = false;
                    break;
                }
            }
            inputFile.close();
        }
    } while (!uniqueAccountNumber);
    
    // Input and validate account holder's name
    cin.ignore(); // Clear the newline character left in the input buffer
    cout << "Enter Account Holder's Name: ";
    getline(cin, newAccount.name);
    
    // Input and validate initial balance (must be non-negative)
    do {
        cout << "Enter Initial Balance: ";
        cin >> newAccount.balance;
        if (newAccount.balance < 0) {
                            system("cls");
            cout << RED <<"Initial balance cannot be negative. Please enter a valid balance."<<RESET_COLOR  << endl;
        }
    } while (newAccount.balance < 0);

    // Save the new account to the file
    ofstream outputFile("accounts.dat", ios::app); // Append mode
    outputFile << newAccount.accountNumber << " " << newAccount.name << " " << newAccount.balance << endl;
    outputFile.close();
    system("cls");
    cout << GREEN << "\nAccount created successfully!" << RESET_COLOR<< endl;
    cout << "\n\n                               Enter any key to continue : ";
    cin >> Beginner_word_or_char;
                    system("cls");

}

void createLoanBook(vector<Loan>& loans) {
    int loanAccountNumber;
    string loanTakerName = "";
    string payingDate = "0000-00-00";
    double paidAmount = 0.0;

    cout <<"Welcome to the Loan Book Creation Portal" << endl;

    cout << "you have a savings account with us? If so, enter \"y\": ";
 
    string hasSavingsAccount;
    cin >> hasSavingsAccount;
    system("cls"); // Clear the screen

    if (hasSavingsAccount != "y" && hasSavingsAccount != "Y") {
        system("cls");
        cout << "Sorry, you can't access this without a savings account." << endl;
           cout << "\t\tEnter any key to continue :  ";
           cin >> Beginner_word_or_char;
                   system("cls");
        return;
    }

    int savingAccountNumber;
    cout << "You Need to verify your saving account:\n";
    cout << "Please enter your savings account number: ";
    cin >> savingAccountNumber;
    system("cls"); // Clear the screen

    // Check if the savings account number exists in the bank's accounts file
    ifstream accountsFile("accounts.dat");
    bool accountExists = false;

    if (accountsFile) {
        int accountNumber;
        string name;
        double balance;

        while (accountsFile >> accountNumber >> name >> balance) {
            if (accountNumber == savingAccountNumber) {
                accountExists = true;
                loanTakerName = name;  // Set the loan taker's name from the savings account
                loanAccountNumber = accountNumber;  // Set the loan account number from the savings account
                break;
            }
        }
        accountsFile.close();
    } else {
        cout << "Error reading accounts file." << std::endl;
        return;
    }

    if (!accountExists) {
        system("cls"); // Clear the screen
        cout << "Savings account not found. Please create a savings account first." << endl;
                cout << "Enter any key to continue : ";
                cin >> Beginner_word_or_char;
                        system("cls");
        return;
    }
    system("cls"); // Clear the screen

    cout << "You are eligible to open the Loan Book:" << endl;

    // Check if a loan with the same account number already exists in the file
    ifstream loanFile("loans.dat");
    bool loanExists = false;

    if (loanFile) {
        int existingLoanAccountNumber;
        string existingLoanTakerName;
        string existingPayingDate;
        double existingPaidAmount;
        double existingLoanAmount;

        while (loanFile >> existingLoanAccountNumber >> existingLoanTakerName >> existingPayingDate >> existingPaidAmount >> existingLoanAmount) {
            if (existingLoanAccountNumber == loanAccountNumber) {
                system("cls"); // Clear the screen
                cout << RED <<  "A loan book already exists for this loan account." << RESET_COLOR<< endl;
                loanExists = true;
                break;
            }
        }
        loanFile.close();
    } else {
        cout << "Error reading loan file." << std::endl;
        return;
    }

    if (loanExists) {
        return;
    }

    // Create the loan book entry
    Loan newLoan;
    newLoan.loanTakerName = loanTakerName;
    newLoan.loanAccountNumber = loanAccountNumber;
    newLoan.payingDate = payingDate;
    newLoan.paidAmount = paidAmount;
    newLoan.amountRemaining = 0.0;  // Default value for remaining amount

    // Save all loan data to the "loans.dat" file
    ofstream loanOutputFile("loans.dat", ios::app);

    if (loanOutputFile) {
        loanOutputFile << newLoan.loanAccountNumber << " " << newLoan.loanTakerName << " " << newLoan.payingDate << " " << newLoan.paidAmount << " " << newLoan.amountRemaining << endl;
                system("cls");
        cout << GREEN << "Loan book created successfully and saved to 'loans.dat'." << RESET_COLOR << endl;
        loanOutputFile.close();

        cout << "\n**********************************************\n";
        cout << "Name: " << newLoan.loanTakerName << endl;
        cout << "Account_number: " << newLoan.loanAccountNumber << endl;
        cout << "\n**********************************************\n";
                cout << "\n\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");



    } 
    else {
        loanOutputFile << newLoan.loanAccountNumber << " " << newLoan.loanTakerName << " " << newLoan.payingDate << " " << newLoan.paidAmount << " " << newLoan.amountRemaining << endl;
        
                system("cls");
        cout <<GREEN  << "Loan book created successfully : " << RESET_COLOR << endl;
         loanOutputFile.close();
        // Display the name and account number
        cout << "Name: " << newLoan.loanTakerName << endl;
        cout << "Account_number: " << newLoan.loanAccountNumber << endl;
                        cout << "Enter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
    }

    // Add the loan book entry to the vector
    loans.push_back(newLoan);
}

void makeMonthlyRepayment(vector<Loan>& loans) {
    system("cls");
    int loanAccountNumber;
    string payingDate;
    double repaymentAmount;

    cout << BOLD_GREEN << "Welcome to the Monthly Repayment Portal" << RESET_COLOR << endl;

    cout << "Please enter your loan account number: ";
    cin >> loanAccountNumber;
        system("cls");

    // Check if the loan account number exists in the bank's loan file
    ifstream loanFile("loans.dat");
    bool accountExists = false;
    Loan userLoan;

    if (loanFile) {
        int existingLoanAccountNumber;
        string existingLoanTakerName;
        string existingPayingDate;
        double existingPaidAmount;
        double existingLoanAmount;

        while (loanFile >> existingLoanAccountNumber >> existingLoanTakerName >> existingPayingDate >> existingPaidAmount >> existingLoanAmount) {
            if (existingLoanAccountNumber == loanAccountNumber) {
                accountExists = true;
                userLoan.loanTakerName = existingLoanTakerName;
                userLoan.loanAccountNumber = existingLoanAccountNumber;
                userLoan.payingDate = existingPayingDate;
                userLoan.paidAmount = existingPaidAmount;
                userLoan.amountRemaining = existingLoanAmount;
                break;
            }
        }
        loanFile.close();
    } else {
        cout << "Error reading loan file." << endl;
        return;
    }

    if (!accountExists) {
        cout <<RED <<"Loan account not found. Please enter a valid loan account number."<< RESET_COLOR << endl;
        return;
    }

    // Get the current date and time
    time_t now = time(0);
    tm* currentDate = localtime(&now);

    int currentYear = 1900 + currentDate->tm_year;
    int currentMonth = 1 + currentDate->tm_mon;
    int currentDay = currentDate->tm_mday;

    // Convert the user's paying date string to integers
    int payingYear, payingMonth, payingDay;
    stringstream dateStream(userLoan.payingDate);
    dateStream >> payingYear >> payingMonth >> payingDay;

    // Check if it's time for the user to make a payment
    if (currentYear > payingYear || (currentYear == payingYear && currentMonth > payingMonth) || (currentYear == payingYear && currentMonth == payingMonth && currentDay > payingDay)) {
        cout << "It's time to make a payment. You will be charged a penalty of 0.05% of the remaining amount." << endl;
        // Calculate and apply the penalty
        double penalty = 0.0005 * userLoan.amountRemaining;
        userLoan.amountRemaining += penalty;
        cout << "Penalty Applied: $" << fixed << setprecision(2) << penalty << endl;
    } else {
        cout << "It's not time to make a payment yet." << endl;
        cout << "Your next payment date is: " << userLoan.payingDate << endl;
        cout << "Please come back on that date to make a payment." << endl;
        return;
    }

    // Accept the repayment amount
    cout << "Please enter the amount you want to repay: $";
    cin >> repaymentAmount;

    if (repaymentAmount >= 0.0) {
        // Update the loan record
        userLoan.amountRemaining -= repaymentAmount;
        userLoan.paidAmount += repaymentAmount;

        // Calculate the next payment date
        payingMonth++;
        if (payingMonth > -12) {
            payingMonth = 1;
            payingYear++;
        }
    userLoan.payingDate = to_string(payingYear) + "-" + to_string(payingMonth) + "-" + to_string(payingDay);
               // Update the loan file
        ofstream loanFile("loans.dat");
        if (loanFile) {
            for (Loan& loan : loans) {
                if (loan.loanAccountNumber == userLoan.loanAccountNumber) {
                    loanFile << loan.loanAccountNumber << " " << loan.loanTakerName << " " << userLoan.payingDate << " " << userLoan.paidAmount << " " << userLoan.amountRemaining << endl;
                } else {
                    loanFile << loan.loanAccountNumber << " " << loan.loanTakerName << " " << loan.payingDate << " " << loan.paidAmount << " " << loan.amountRemaining << endl;
                }
            }
            loanFile.close();
            cout << "Payment successful!" << endl;
            cout << "Remaining Amount: $" << fixed << setprecision(2) << userLoan.amountRemaining << endl;
            cout << "Next Payment Date: " << payingYear << "-" << setw(2) << setfill('0') << payingMonth << "-" << setw(2) << setfill('0') << payingDay << endl;
        } else {
            cout << "Error updating loan file." << endl;
        }
    } else {
        cout << "Invalid repayment amount. Please enter a non-negative amount." << endl;
    }
}

void createLoanAgreement() {
    system("cls");
    cout <<BOLD_BLUE << "Welcome to the Loan Agreement Portal" << RESET_COLOR << endl;

    // Display bank's terms and policies
    cout << MAGENTA << "Bank Terms and Policies:" << endl;
    cout << "1. The user must provide collateral worth more than 2 times the loan amount." << endl;
    cout << "2. The service charge is 12% of the loan amount for a 1-year term, 24% for a 2-year term, and so on." << RESET_COLOR << endl;
    // Get user input
    string userName;
    int userAccountNumber;
    double loanAmount;
    int loanTermYears;
    int loanDay; // Day of the month for payingDate

    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, userName);
    cout << "Please enter your account number: ";
    cin >> userAccountNumber;
    // Check if the account exists and the user's name matches
    ifstream accountsFile("accounts.dat");
    bool accountExists = false;

    if (accountsFile) {
        int accountNumber;
        string name;
        double balance;

        while (accountsFile >> accountNumber >> name >> balance) {
            if (accountNumber == userAccountNumber && name == userName) {
                accountExists = true;

                // Check if the user has an outstanding loan balance
                ifstream loanFile("loans.dat");
                bool hasOutstandingLoan = false;

                if (loanFile) {
                    int existingLoanAccountNumber;
                    string existingLoanTakerName;
                    string existingPayingDate;
                    double existingPaidAmount;
                    double existingLoanAmount;
                    vector<string> loanData; // Store loan data temporarily

                    while (loanFile >> existingLoanAccountNumber >> existingLoanTakerName >> existingPayingDate >> existingPaidAmount >> existingLoanAmount) {
                        if (existingLoanAccountNumber == userAccountNumber && existingPaidAmount < existingLoanAmount) {
                            hasOutstandingLoan = true;

                            // Update the loan data if it matches the user's account number
                            existingPayingDate = calculateStartPaymentDate(); // Calculate start payment date
                            existingLoanAmount += loanAmount; // Add the new loan amount
                            loanData.push_back(to_string(existingLoanAccountNumber) + " " + existingLoanTakerName + " " + existingPayingDate + " " + to_string(existingPaidAmount) + " " + to_string(existingLoanAmount));
                        } else {
                            loanData.push_back(to_string(existingLoanAccountNumber) + " " + existingLoanTakerName + " " + existingPayingDate + " " + to_string(existingPaidAmount) + " " + to_string(existingLoanAmount));
                        }
                    }
                    loanFile.close();

                    // Write the updated loan data back to the file
                    ofstream tempLoanFile("temp_loans.dat");
                    if (tempLoanFile) {
                        for (const string& line : loanData) {
                            tempLoanFile << line << endl;
                        }
                        tempLoanFile.close();

                        // Remove the old file and rename the temporary file
                        remove("loans.dat");
                        rename("temp_loans.dat", "loans.dat");
                        cout <<GREEN << "************************************"<< RESET_COLOR << endl;
                    } else {
                        cout << "Error updating loan agreement." << endl;
                    }
                }

                if (hasOutstandingLoan) {
                          system("cls");
                    cout <<RED << "You have an outstanding loan. Please repay your previous loan before applying for a new one."<< RESET_COLOR << endl;
                                       cout << "\t\tEnter any key to continue : ";
                                        cin >> Beginner_word_or_char;
                                         system("cls");
                    return;
                }

                break;
            }
        }
        accountsFile.close();
    }

    if (!accountExists) {
                   system("cls");
        cout << RED << "Account not found or name mismatch. Loan agreement canceled." << RESET_COLOR<< endl;
                cout << "Enter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");

        return;
    }

    cout << "Please enter the amount you want to borrow: $";
    cin >> loanAmount;
    cout << "Please enter the length of the loan term in years: ";
    cin >> loanTermYears;
    // Validate and get the day of the month for payingDate
    do {
        cout << "Please enter the day of the month for payingDate (1-31): ";
        cin >> loanDay;
    } while (loanDay <= 0 || loanDay > 31);

    // Validate and get the year for payingDate (greater than or equal to 2023)
    int loanYear;
    do {
        cout << "Please enter the year for payingDate (must be greater than or equal to 2023): ";
        cin >> loanYear;
    } while (loanYear < 2023);

    // Validate and get the month for payingDate (1-12)
    int loanMonth;
    do {
        cout << "Please enter the month for payingDate (1-12): ";
        cin >> loanMonth;
    } while (loanMonth < 1 || loanMonth > 12);

    // Cast the integer values to string for payingDate in the format "year-month-day"
    string payingDate = to_string(loanYear) + "-" + to_string(loanMonth) + "-" + to_string(loanDay);

    // Calculate loan details
    double serviceChargeRate = 0.12 * loanTermYears; // Service charge rate based on the term
    double serviceCharge = loanAmount * serviceChargeRate;
    double totalLoanAmount = loanAmount + serviceCharge;
                      system("cls");
    // Display loan details
    cout << BOLD_BLUE <<"Loan Agreement Details:" << RESET_COLOR<< endl;
    cout << "User: " << userName << endl;
    cout << "Account Number: " << userAccountNumber << endl;
    cout << "Loan Amount: $" << loanAmount << endl;
    cout << "Loan Term (Years): " << loanTermYears << endl;
    cout << "Service Charge Rate: " << serviceChargeRate * 100 << "%" << endl;
    cout << "Service Charge: $" << serviceCharge << endl;
    cout << "Total Loan Amount: $" << totalLoanAmount << endl;
    cout << "Paying Date: " << payingDate << endl;
    
    // Confirm the loan agreement
    char confirm;
    cout << "Do you want to confirm this loan agreement? (y/n): ";
    cin >> confirm;
            system("cls");

    if (confirm == 'y' || confirm == 'Y') {
        cout << "Loan agreement confirmed. Your loan has been approved." << endl;
                cout << "Enter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
        // Update the user's loan status to indicate they have a new loan
 ifstream loanInputFile("loans.dat");
 ofstream tempLoanFile("temp_loans.dat");

 if (loanInputFile && tempLoanFile) {
    int existingLoanAccountNumber;
    string existingLoanTakerName;
    string existingPayingDate;
    double existingPaidAmount;
    double existingLoanAmount;

    while (loanInputFile >> existingLoanAccountNumber >> existingLoanTakerName >> existingPayingDate >> existingPaidAmount >> existingLoanAmount) {
        if (existingLoanAccountNumber == userAccountNumber) {
            existingPayingDate = payingDate; // Update the paying date
            existingLoanAmount += loanAmount; // Add the new loan amount
        }

        // Write the existing or updated loan data to the temporary file
        tempLoanFile << existingLoanAccountNumber << " " << existingLoanTakerName << " " << existingPayingDate << " " << existingPaidAmount << " " << existingLoanAmount << endl;
    }

    loanInputFile.close();
    tempLoanFile.close();

    // Remove the old file and rename the temporary file
    remove("loans.dat");
    rename("temp_loans.dat", "loans.dat");
    cout << BOLD_GREEN <<"Loan agreement updated successfully."   <<RESET_COLOR <<endl;
 } 

    
 else {
    cout << "Error updating loan agreement." << endl;
   }
    }

}

void displayLoanBook() {
    const string filename = "loans.dat";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return;
    }

    cout << "Loan Book Contents:" << endl;

    int loanAccountNumber;
    string loanTakerName, payingDate;
    double paidAmount, amountRemaining;

    bool isEmpty = true;  // Flag to check if the file is empty

    // Display table headers
    cout << setw(20) << left << "Loan Account Number" << setw(20) << left << "Loan Taker Name"
         << setw(15) << left << "Paying Date" << setw(15) << left << "Paid Amount" << setw(20) << left << "Amount Remaining" << endl;
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;  // Separator line

    while (inputFile >> loanAccountNumber >> loanTakerName >> payingDate >> paidAmount >> amountRemaining) {
        isEmpty = false;  // Set the flag to false if any records are found
        cout << setw(20) << left << loanAccountNumber << setw(20) << left << loanTakerName
             << setw(15) << left << payingDate << setw(15) << left << paidAmount << setw(20) << left << amountRemaining << endl;
    }

    inputFile.close();

    if (isEmpty) {
        cout << "No loan book is found." << endl;
    }
}
void depositFunds() {
    system("cls");
    int accountNumber;
    double depositAmount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    ifstream inputFile("accounts.dat",ios::in);
    ofstream tempFile("temp.dat",ios::out);

    bool found = false;

    if (inputFile && tempFile) {
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            if (account.accountNumber == accountNumber) {
                found = true;

                cout << "Account Holder: " << account.name << endl;
                cout << "Current Balance: $" << account.balance << endl;

                // Input and validate the deposit amount (must be non-negative)
                do {
                    cout << "Enter Deposit Amount: $";
                    cin >> depositAmount;
                    if (depositAmount < 0) {
                        system("cls");
                        cout << RED << "Deposit amount cannot be negative. Please enter a valid amount."<< RESET_COLOR << endl;
                    }
                } while (depositAmount < 0);

                // Update the balance and write to the temp file
                account.balance += depositAmount;
                tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
                system("cls");
                cout << GREEN << "Deposit successful!"  << RESET_COLOR << endl;
                cout << "\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");                
            } else {
                // Copy other accounts to the temp file
                tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
            }
        }
        inputFile.close();
        tempFile.close();

        // Remove the old accounts file and rename the temp file
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");

        if (!found) {
            system("cls");
            cout <<  RED <<"Account not found. Please enter a valid account number." << RESET_COLOR << endl;
            cout << "\t\tEnter any key to contiue : ";
            cin >> Beginner_word_or_char;
            system("cls");
        }
    } else {
        cout << "Error opening files." << endl;
    }
}

void withdrawFunds() {
    system("cls");
    int accountNumber;
    double withdrawalAmount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    system("cls");
    ifstream inputFile("accounts.dat");
    ofstream tempFile("temp.dat");

    bool found = false;

    if (inputFile && tempFile) {
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            if (account.accountNumber == accountNumber) {
                found = true;

                cout << "Account Holder: " << account.name << endl;
                cout << "Current Balance: $" << account.balance << endl;

                // Input and validate the withdrawal amount (must be non-negative)
                do {
                    cout << "Enter Withdrawal Amount: $";
                    cin >> withdrawalAmount;
                        system("cls");
                    if (withdrawalAmount < 0) {
                        cout <<  RED <<"Withdrawal amount cannot be negative. Please enter a valid amount." <<  RESET_COLOR <<endl;
                    } else if (withdrawalAmount > account.balance) {
                        cout << RED << "Insufficient balance. Please enter a valid amount." <<  RESET_COLOR <<endl;
                    }
                } while (withdrawalAmount < 0 || withdrawalAmount > account.balance);

                // Update the balance and write to the temp file
                account.balance -= withdrawalAmount;
                tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
                    system("cls");
                cout << GREEN <<"Withdrawal successful!" << RESET_COLOR << endl;
                cout << "\t\tEnter any key to continue : ";
                cin >>Beginner_word_or_char;
                    system("cls");

            } else {
                // Copy other accounts to the temp file
                tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
            }
        }
        inputFile.close();
        tempFile.close();

        // Remove the old accounts file and rename the temp file
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");

        if (!found) {
                system("cls");
            cout <<  RED << "Account not found. Please enter a valid account number." << endl;
        }
    } else {
        cout << "Error opening files." << endl;
    }
}

void transferFunds() {
    system("cls");
    int senderAccountNumber, receiverAccountNumber;
    double transferAmount;

    cout << "Enter Sender's Account Number: ";
    cin >> senderAccountNumber;
    cout << "Enter Receiver's Account Number: ";
    cin >> receiverAccountNumber;

    ifstream inputFile("accounts.dat");
    ofstream tempFile("temp.dat");

    bool senderFound = false, receiverFound = false;

    if (inputFile && tempFile) {
        BankAccount senderAccount, receiverAccount;
        while (inputFile >> senderAccount.accountNumber >> senderAccount.name >> senderAccount.balance) {
            if (senderAccount.accountNumber == senderAccountNumber) {
                senderFound = true;

                cout << "Sender's Account Holder: " << senderAccount.name << endl;
                cout << "Sender's Current Balance: $" << senderAccount.balance << endl;

                // Input and validate the transfer amount (must be non-negative)
                do {
                    cout << "Enter Transfer Amount: $";
                    cin >> transferAmount;
                    if (transferAmount < 0) {
                            system("cls");
                        cout <<  RED <<"Transfer amount cannot be negative. Please enter a valid amount." << RESET_COLOR << endl;
                    } else if (transferAmount > senderAccount.balance) {
                            system("cls");
                        cout << RED << "Insufficient balance for the transfer. Please enter a valid amount."<< RESET_COLOR<< endl;
                    }
                } while (transferAmount < 0 || transferAmount > senderAccount.balance);
                
                // Update the sender's balance and write to the temp file
                senderAccount.balance -= transferAmount;
                tempFile << senderAccount.accountNumber << " " << senderAccount.name << " " << senderAccount.balance << endl;

                // Search for the receiver's account
                while (inputFile >> receiverAccount.accountNumber >> receiverAccount.name >> receiverAccount.balance) {
                    if (receiverAccount.accountNumber == receiverAccountNumber) {
                        receiverFound = true;
                        
                        // Update the receiver's balance and write to the temp file
                        receiverAccount.balance += transferAmount;
                        tempFile << receiverAccount.accountNumber << " " << receiverAccount.name << " " << receiverAccount.balance << endl;
                            system("cls");
                        cout << GREEN <<"\nTransfer successful!" << endl;

                        cout << "\t\tEnter any key to continune : " << RESET_COLOR;
                        cin >>Beginner_word_or_char;
                            system("cls");
                        break;
                    }
                }

                if (!receiverFound) {
                        system("cls");
                    cout <<RED <<"Receiver's account not found. Please enter a valid receiver account number."  << RESET_COLOR << endl;
                }
            } else {
                // Copy other accounts to the temp file
                tempFile << senderAccount.accountNumber << " " << senderAccount.name << " " << senderAccount.balance << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        // Remove the old accounts file and rename the temp file
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");

        if (!senderFound) {
                system("cls");
            cout << RED << "Sender's account not found. Please enter a valid sender account number." << RESET_COLOR << endl;
        }
    } else {
        cout << "Error opening files." << endl;
    }
}

void viewCurrentBalance() {
    system("cls");
    int accountNumber;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
                system("cls");

    ifstream inputFile("accounts.dat");

    bool accountFound = false;

    if (inputFile) {
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            if (account.accountNumber == accountNumber) {
                accountFound = true;
                cout << "Holder Name: " << account.name << endl;
                cout << "Holder Account: " << account.accountNumber << endl;
                cout << "-------------------------------------------" << endl;
                ifstream transactionFile("transactions.dat");
                string transactionType;
                double currentBalance = account.balance;

                cout << "Current Amount: $" << currentBalance << endl;
                                cout << "\n\t\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
                break;
            }
        }

        inputFile.close();

        if (!accountFound) {
            cout << "Account not found. Please enter a valid account number." << endl;
        }
    } else {
        cout << "Error opening files." << endl;
    }
}

void calculateAndAddInterest() {
    system("cls");
    string userType;
    
    cout << RED << "This is can only be accesed by the head of the bank or an accountant\n" << RESET_COLOR ;
    cout << "Are you an accountant or the head of the bank? (Type 'accountant' or 'head'): ";
    cin >> userType;

    if (userType == "accountant" || userType == "head") {
        string accountantName, password;

        cout << "Enter your first name: ";
        cin >> accountantName;

        cout << "Enter your password: ";
        cin >> password;

        // Check the password
        string expectedPassword = accountantName + "Head@Bank" + accountantName;
        if (password == expectedPassword) {
            int accountNumber;
            int months;

            cout << "Enter the account number: ";
            cin >> accountNumber;

            ifstream inputFile("accounts.dat");
            ofstream tempFile("temp.dat");

            bool accountFound = false;

            if (inputFile && tempFile) {
                BankAccount account;
                while (inputFile >> account.accountNumber >> account.name >> account.balance) {
                    if (account.accountNumber == accountNumber) {
                        accountFound = true;
                        cout << "\n***************************************\n";
                        cout << "Account Holder: " << account.name << endl;
                        cout << "Current Balance: $" << account.balance << endl;

                        // Input and validate the time period for interest calculation
                        cout << "Enter the number of months passed since deposit: ";
                        cin >> months;

                        if (months < 0) {
                            cout << RED << "Invalid number of months. Please enter a valid value." << RESET_COLOR << endl;
                            continue;
                        }

                        // Calculate interest (0.07% annual rate)
                        double annualInterestRate = 0.07;
                        double monthlyInterestRate = annualInterestRate / 12;
                        double interest = (account.balance * monthlyInterestRate * months) / 100;

                        // Update the balance and write to the temp file
                        account.balance += interest;
                        tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
                        cout << BOLD_BLUE << "Interest calculated and added successfully!" <<RESET_COLOR << endl;
                cout << "\n\t\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
                    } else {
                        // Copy other accounts to the temp file
                        tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
                    }
                }
                inputFile.close();
                tempFile.close();

                // Remove the old accounts file and rename the temp file
                remove("accounts.dat");
                rename("temp.dat", "accounts.dat");

                if (!accountFound) {
                cout << RED << "Account not found. " <<RESET_COLOR << endl;                
                cout << "\n\t\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
                }
            } else {
                cout << "Error opening files." << endl;
            }
        } else {
            cout << RED << "Incorrect password. Access denied." << RESET_COLOR << endl;
                cout << "\n\t\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
        }
    } else {
                system("cls");
        cout << RED<< "You can't add interest to your account."  << RESET_COLOR<< endl;
                cout << "\n\t\t\tEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
    }

}

void closeAccountWithBalance(int accountNumberToClose) {
    system("cls");
    ifstream inputFile("accounts.dat");
    ofstream tempFile("temp.dat");

    bool accountFound = false;

    if (inputFile && tempFile) {
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            if (account.accountNumber == accountNumberToClose) {
                accountFound = true;
                cout << "Closing account for: " << account.name << endl;
                cout << "Account Number: " << account.accountNumber << endl;
                cout << "Current Balance: $" << account.balance << endl;

                // Check if there's a remaining balance
                if (account.balance > 0) {
                    char choice;
                    cout << "You have a remaining balance of $" << account.balance << endl;
                    cout << "Do you want to withdraw the remaining amount (W)? ";
                    cin >> choice;
                    if (choice == 'W' || choice == 'w') {
                        // Withdraw remaining balance
                        double withdrawalAmount = account.balance;
                        account.balance = 0;
                        cout << "Withdrew remaining balance: $" << withdrawalAmount << endl;
                    } else {
                        cout << "Invalid choice. The remaining balance was not withdrawn." << endl;
                    }
                }

                cout << "Account successfully closed!" << endl;
            } else {
                // Copy other accounts to the temp file
                tempFile << account.accountNumber << " " << account.name << " " << account.balance << endl;
            }
        }
        inputFile.close();
        tempFile.close();

        // Remove the old accounts file and rename the temp file
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");

        if (!accountFound) {
            cout << "Account not found. Please enter a valid account number." << endl;
        }
    } else {
        cout << "Error opening files." << endl;
    }
}

void listAllAccounts() {
    ifstream inputFile("accounts.dat");

    if (inputFile) {
        cout <<BOLD_BLUE <<"________________________________________________________________________________" << endl;
        cout << BOLD_GREEN << "                             Users" << endl;
        cout << BOLD_RED <<"_________________________________________________________________________________:" << endl;
         cout << BOLD_GREEN;
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            cout << BOLD_GREEN;
            cout << "Name: " << account.name << endl;
            cout << "Account Number: " << account.accountNumber << endl;
            cout << "Balance: $" << account.balance << endl;
            cout  << BOLD_RED << "________________________________________________________________________________" << RESET_COLOR <<  endl;
         
        }
                cout << "\n\t\t\tEnter any key to continue :  " << RESET_COLOR;
                cin >> Beginner_word_or_char;
                system("cls");
        inputFile.close();
    } else {
        cout << "Error opening the accounts file." << endl;
    }
}


double calculateTotalAmountInBank() {
    ifstream inputFile("accounts.dat");
    double totalAmount = 0.0;

    if (inputFile) {
        BankAccount account;
        while (inputFile >> account.accountNumber >> account.name >> account.balance) {
            totalAmount += account.balance;
        }
        inputFile.close();
    } else {
        cout << "Error opening the accounts file." << endl;
    }

    return totalAmount;
}

void deleteAllAccounts() {
    const char* accountsFileName = "accounts.dat";

    // Create a new empty file to replace the existing "accounts.dat" file
    ofstream outputFile(accountsFileName);

    if (outputFile) {
        outputFile.close();
                system("cls");
        cout << BOLD_GREEN <<"All accounts have been deleted from the bank." << endl;
                cout << "\n\nEnter any key to continue : ";
                cin >> Beginner_word_or_char;
                system("cls");
                cout << RESET_COLOR;
                system("cls");

    } else {
        cout << "Error opening the accounts file." << endl;
    }
}


string calculateStartPaymentDate() {
    // Get the current date
    time_t currentTime;
    struct tm* localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Calculate the start payment date (one month later)
    int year = localTime->tm_year + 1900; // Year starts from 1900 in struct tm
    int month = localTime->tm_mon + 1;    // Month is 0-based
    int day = localTime->tm_mday;

    month++; // Increment month by 1 for one month later

    if (month > 12) {
        month = 1;
        year++;
    }

    // Format the date as "year-month-day"
    string startPaymentDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

    return startPaymentDate;
}

void BANK_MANAGEMENT(){
            system("cls");
 cout << "GROUP MEMBERS" << setw(40) << "ID" << endl;
    cout << GREEN << "1. Haylemeskel Haylemariam" << setw(36) << "ETS 0756/14" << RESET_COLOR << endl;
    cout << YELLOW << "2. Haymanot Aweke" << setw(46) << "ETS 0757/14" << RESET_COLOR << endl;
    cout << BLUE << "3. Henok Asegedew" << setw(45) << "ETS 0776/14" << RESET_COLOR << endl;
    cout << MAGENTA << "4. Gelead worku" << setw(46) << "ETS 0689/14" << RESET_COLOR << endl;
    cout << CYAN << "5. Fisseha Akele" << setw(46) << "ETS 0675/14" << RESET_COLOR << endl;
    cout << "6. Feven Alemayehu" << setw(45) << "ETS 0634/14" << RESET_COLOR << endl;

   
    // Red text
    cout << RED << "             #######  " << RESET_COLOR << endl;
    cout << RED << "             ##    )) " << RESET_COLOR << endl;
    cout << RED << "             ######  " << RESET_COLOR << endl;
    cout << RED << "             ##    )) " << RESET_COLOR << endl;
    cout << RED << "             ####### " << RESET_COLOR << endl << endl;

    // Green text
    cout << GREEN << "            *****   " << RESET_COLOR << endl;
    cout << GREEN << "           *** ***  " << RESET_COLOR << endl;
    cout << GREEN << "          ***   *** " << RESET_COLOR << endl;
    cout << GREEN << "         **********" << RESET_COLOR << endl;
    cout << GREEN << "         ***     *** " << RESET_COLOR << endl;
    cout << GREEN << "        ***       *** " << RESET_COLOR << endl;

    // Yellow text
    cout << YELLOW << "          ## ##    ##" << RESET_COLOR << endl;
    cout << YELLOW << "          ##  ##   ##" << RESET_COLOR << endl;
    cout << YELLOW << "          ##   ##  ##" << RESET_COLOR << endl;
    cout << YELLOW << "          ##    ## ##" << RESET_COLOR << endl;

    // Red text
    cout << RED << "             ##  ##     " << RESET_COLOR << endl;
    cout << RED << "             ## ##      " << RESET_COLOR << endl;
    cout << RED << "             ###       " << RESET_COLOR << endl;
    cout << RED << "             ## ##     " << RESET_COLOR << endl;
    cout << RED << "             ##   ##    " << RESET_COLOR << endl;

    cout <<"             *****************************************************";
    cout << BOLD_BLUE<<"             \n                  Management System!               *\n" << RESET_COLOR;
    cout <<"             ****************************************************\n";

    string begin;
    cout << "                        Enter any key to start : ";
    cin >> begin;
        system("cls");


}