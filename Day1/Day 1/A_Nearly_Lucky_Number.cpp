#include <iostream>

using namespace std;

// Function to count the number of lucky digits in a number
int countLuckyDigits(long long n) {
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 4 || digit == 7) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;

    // Count the lucky digits in the given number
    int luckyDigitCount = countLuckyDigits(n);

    // Check if the count is a lucky number
    if (luckyDigitCount == 4 || luckyDigitCount == 7 || luckyDigitCount == 47 || luckyDigitCount == 74) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
