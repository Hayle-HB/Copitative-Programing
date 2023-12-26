#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const char* filename = "account.txt";
 
// Define a structure to represent an account
struct Account {
    int accountNumber;
    string accountName;
    double balance;
};


void CreateAccount(vector<Account>& account){
 ofstream outFile(filename, ios::app);
    
Account acc;

cout << "Enter Holder  name : ";
cin.ignore();
getline(acc.accountName);


}


int main()
{


Account acc;

vector<>





  return 0;
}