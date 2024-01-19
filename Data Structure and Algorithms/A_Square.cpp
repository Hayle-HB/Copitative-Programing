#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, x2, y1, y2, z1, z2, w1, w2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2 >> w1 >> w2;

        int Min1 = min({x1, y1, z1, w1});
        int Min2 = min({x2, y2, z2, w2});
        int Max1 = max({x1, y1, z1, w1});
        int Max2 = max({x2, y2, z2, w2});

        cout << abs((Max1 - Min1) * (Max2 - Min2)) << endl;
    }

    return 0;
}
