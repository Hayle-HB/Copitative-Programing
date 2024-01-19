#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int w, d, h;
        std::cin >> w >> d >> h;

        int a, b, f, g;
        std::cin >> a >> b >> f >> g;

        int result = 0;

        if (a >= f && a <= f + h) {
            result += std::abs(b - g);
        } else {
            int distance = std::min(std::min(a, w - a), w);
            result += distance + std::abs(b - h);
        }

        std::cout << result << "\n";
    }

    return 0;
}
