#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        if (n < 3 || n % 3 == 0) {
            // There is no valid triplet
            std::cout << "NO" << std::endl;
        } else {
            // Print a valid triplet
            std::cout << "YES" << std::endl;
            std::cout << "1 2 " << n - 3 << std::endl;
        }
    }

    return 0;
}
