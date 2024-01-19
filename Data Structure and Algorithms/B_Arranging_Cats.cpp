#include <iostream>
#include <vector>

using namespace std;

int min_operations(int n, const string& s, const string& f) {
    int days = 0;
    int cats_in_boxes = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            cats_in_boxes++;
        }
        if (f[i] == '1' && s[i] == '0') {
            days++;  // Add a cat if it's not already in the box
        }
    }

    return max(days, cats_in_boxes);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s, f;
        cin >> s >> f;

        cout << min_operations(n, s, f) << endl;
    }

    return 0;
}
