#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int operations = 0;
        int current_max = a[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > current_max) {
                current_max = a[i];
            } else {
                operations++;
            }
        }

        cout << operations << endl;
    }

    return 0;
}
