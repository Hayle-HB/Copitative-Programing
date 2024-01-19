#include <iostream>
#include <vector>

std::vector<std::string> can_impress(int t, const std::vector<std::pair<int, std::vector<int>>>& test_cases) {
    std::vector<std::string> results;
    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        const std::vector<int>& glasses = test_case.second;
        std::vector<int> prefix_sum(n + 1, 0);

        for (int j = 1; j <= n; ++j) {
            prefix_sum[j] = prefix_sum[j - 1] + (j % 2 == 1 ? glasses[j - 1] : -glasses[j - 1]);
        }

        bool found = false;
        for (int l = 1; l <= n && !found; ++l) {
            for (int r = l + 1; r <= n; ++r) {
                if (prefix_sum[r] - prefix_sum[l - 1] == 0) {
                    found = true;
                    break;
                }
            }
        }

        results.emplace_back(found ? "YES" : "NO");
    }

    return results;
}

int main() {
    int t;
    std::cin >> t;

    std::vector<std::pair<int, std::vector<int>>> test_cases;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> glasses(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> glasses[j];
        }
        test_cases.emplace_back(n, glasses);
    }

    std::vector<std::string> results = can_impress(t, test_cases);
    for (const std::string& result : results) {
        std::cout << result << '\n';
    }

    return 0;
}
