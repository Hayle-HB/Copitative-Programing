#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_set<int> x_set, y_set;

        // Read the coordinates of special points
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            x_set.insert(x);
            y_set.insert(y);
        }

        // Check if it's possible to visit all special points using at most 3 buttons
        if (x_set.size() == 1 || y_set.size() == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
