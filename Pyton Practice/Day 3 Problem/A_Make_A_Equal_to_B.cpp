#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }

        int operations = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                // If a[i] is not equal to b[i], increment operations
                ++operations;
            }
        }

        std::cout << operations << "\n";
    }

    return 0;
}
