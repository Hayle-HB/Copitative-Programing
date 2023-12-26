#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    bool alphabet[26];
    memset(alphabet, false, sizeof(alphabet));

    for (char c : s) {
        if (isalpha(c)) {
            alphabet[tolower(c) - 'a'] = true;
        }
    }

    bool isPangram = true;
    for (bool seen : alphabet) {
        if (!seen) {
            isPangram = false;
            break;
        }
    }

    cout << (isPangram ? "YES" : "NO") << endl;

    return 0;
}
