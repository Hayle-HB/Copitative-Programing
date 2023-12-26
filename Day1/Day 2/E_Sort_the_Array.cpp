#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int start = -1, end = -1;

    // Find the first element that is not in increasing order
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            start = i;
            break;
        }
    }

    // If the array is already sorted, print "yes" and indices (1 1)
    if (start == -1) {
        cout << "yes\n1 1\n";
        return 0;
    }

    // Find the last element that is not in increasing order
    for (int i = n - 1; i > start; --i) {
        if (a[i] < a[i - 1]) {
            end = i;
            break;
        }
    }

    // Reverse the segment and check if the array becomes sorted
    reverse(a.begin() + start, a.begin() + end + 1);

    // Check if the array is sorted after reversing the segment
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            cout << "no\n";
            return 0;
        }
    }

    // Print "yes" and the indices of the reversed segment
    cout << "yes\n" << start + 1 << " " << end + 1 << "\n";

    return 0;
}
