#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int minOperations(string x, string s) {
    int n = x.length();
    int m = s.length();
    
    int result = INT_MAX;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int j = 0;

        while (j < m && x[i] == s[j]) {
            i++;
            j++;

            if (j == m) {
                result = min(result, cnt + 1);
            }
        }

        if (j == m) {
            i--;
        }
    }

    return (result == INT_MAX) ? -1 : result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int result = minOperations(x, s);
        cout << result << endl;
    }

    return 0;
}
