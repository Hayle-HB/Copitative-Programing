#include <iostream>
#include <cmath>
using namespace std;

int smallestNumberWithUniqueDigitSum(int target_sum) {
    if (target_sum > 45) {
        return -1;
    }

    int current_sum = 0;
    int current_number = 0;

    while (current_sum < target_sum) {
        current_number++;

        // Convert the number to a string for digit manipulation
        string num_str = to_string(current_number);

        current_sum = 0;
        bool isUnique = true;
        bool isFirstDigit = true;

        for (char digit_char : num_str) {
            int digit = digit_char - '0';
            current_sum += digit;
        }
    }

    return (current_sum == target_sum && current_number > 0) ? current_number : -1;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int num;
        cin >> num;
        int result = smallestNumberWithUniqueDigitSum(num);
        cout << result << endl;
    }

    return 0;
}
