#include <iostream>
#include <vector>
#include <algorithm>

struct Operation {
    int index;
    int value;
};

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<Operation> operations;

        int negativeCount = 0;
        long long product = 1;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] < 0) {
                ++negativeCount;
                a[i] = -a[i];
            }
            product *= a[i];
        }

        // Sort the array to minimize the product
        std::sort(a.begin(), a.end());

        // Make one negative number 0 if there are an odd number of negative numbers
        if (negativeCount % 2 == 1) {
            int minNegativeIndex = std::min_element(a.begin(), a.end()) - a.begin();
            operations.push_back({minNegativeIndex, 0});
        }

        // Make all other elements closer to 0 or their original values
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                operations.push_back({i, a[i]});
            }
        }

        std::cout << operations.size() << "\n";
        for (const auto& op : operations) {
            std::cout << op.index + 1 << " " << op.value << "\n";
        }
    }

    return 0;
}
