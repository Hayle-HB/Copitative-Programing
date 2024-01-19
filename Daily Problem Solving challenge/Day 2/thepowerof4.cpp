#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }

        double result = pow(n, 1.0 / 4);
        int result2 = pow(n, 1.0 / 4);
        double fina = result - result2;

        return fina == 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    int numCases;
    std::cin >> numCases;

    while (numCases--) {
        int x;
        std::cin >> x;
        Solution s;
        std::cout << s.isPowerOfFour(x) << std::endl;
    }

    return 0;
}
