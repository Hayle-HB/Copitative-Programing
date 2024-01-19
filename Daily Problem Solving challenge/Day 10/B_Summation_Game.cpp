#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long sum = 0;

        // Alice removes at most k elements
        for (int i = 0; i < min(k, x); ++i) {
            if (a[i] < 0) {
                a[i] *= -1; // Flip negative numbers to positive
            }
        }

        // Bob multiplies at most x elements by -1
        for (int i = 0; i < n; ++i) {
            if (x > 0 && a[i] < 0) {
                a[i] *= -1;
                x--;
            }
        }

        // Calculate the sum of the modified array
        for (int num : a) {
            sum += num;
        }

        cout << sum << endl;
    }

    return 0;
}
