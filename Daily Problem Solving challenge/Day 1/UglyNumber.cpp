#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false; // Ugly numbers are positive integers
        }

        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }

        return n == 1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    cout << s.isUgly(n);

    return 0;
}
