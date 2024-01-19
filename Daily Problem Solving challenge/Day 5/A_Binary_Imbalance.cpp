#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int countZeroes = 0, countOnes = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                countZeroes++;
            } else {
                countOnes++;
            }
        }

        if (countZeroes > countOnes || countZeroes == countOnes) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
