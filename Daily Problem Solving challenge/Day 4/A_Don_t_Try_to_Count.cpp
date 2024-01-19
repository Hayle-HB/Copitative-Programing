#include <iostream>
#include <string>
#include <algorithm>

int minOperations(const std::string& x, const std::string& s) {
    int n = x.size();
    int m = s.size();
    int result = n; // Initialize result to the maximum possible value

    for (int i = 0; i <= n - m; ++i) {
        int operations = 0;
        std::string substring = x.substr(i, m);

        while (substring != s) {
            substring += substring;
            ++operations;

            if (substring.size() > n) {
                // If substring becomes longer than x, it's not possible
                return -1;
            }
        }

        result = std::min(result, operations);
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::string x, s;
        std::cin >> x >> s;

        int result = minOperations(x, s);
        std::cout << result << std::endl;
    }

    return 0;
}
