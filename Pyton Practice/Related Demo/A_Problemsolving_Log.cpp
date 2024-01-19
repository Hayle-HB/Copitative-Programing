#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int time = 0;
        set<char> uniqueChars; 

        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            int num = ch - 'A' + 1;

            if (time + num > n) {
                size_t pos = uniqueChars.size();
                cout << pos << endl;
                break;
            } else if (time + num == n) {
                uniqueChars.insert(ch);
                cout << uniqueChars.size() << endl;
                break;
            } else {
                uniqueChars.insert(ch);
                time += num;
            }
        }
    }

    return 0;
}
