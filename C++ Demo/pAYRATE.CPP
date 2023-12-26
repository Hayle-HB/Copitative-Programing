#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("employee_data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // Define variables for totals
    double totalRegularPay = 0;
    double totalOvertimePay = 0;
    double totalGrossPay = 0;

    // Display the report header
    cout << setw(10) << left << "Name"
         << setw(10) << right << "Pay Rate"
         << setw(10) << "Hours"
         << setw(15) << "Regular Pay"
         << setw(15) << "Overtime Pay"
         << setw(15) << "Gross Pay"
         << endl;

    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

    // Process each line of the input file
    string name;
    double rate, hours;
    while (inputFile >> name >> rate >> hours) {
        double regularPay, overtimePay, grossPay;
        
        if (hours <= 40) {
            regularPay = rate * hours;
            overtimePay = 0;
        } else {
            regularPay = rate * 40;
            overtimePay = (hours - 40) * (rate * 1.5);
        }

        grossPay = regularPay + overtimePay;

        // Display the pay report for the employee
        cout << fixed << setprecision(2)
             << setw(10) << left << name
             << setw(10) << right << rate
             << setw(10) << hours
             << setw(15) << regularPay
             << setw(15) << overtimePay
             << setw(15) << grossPay
             << endl;

        // Update the totals
        totalRegularPay += regularPay;
        totalOvertimePay += overtimePay;
        totalGrossPay += grossPay;
    }

    cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

    // Display the totals
    cout << setw(20) << "Total Regular Pay: " << totalRegularPay << endl;
    cout << setw(20) << "Total Overtime Pay: " << totalOvertimePay << endl;
    cout << setw(20) << "Total Gross Pay: " << totalGrossPay << endl;

    // Close the input file
    inputFile.close();

    return 0;
}
