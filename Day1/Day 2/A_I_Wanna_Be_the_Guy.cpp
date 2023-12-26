#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPresent(n + 1, false);

    int p1;
    cin >> p1;

    int p;

    for (int i = 0; i < p1; i++) {
        cin >> p;
        isPresent[p] = true;
    }

    int p2;
    cin >> p2;

    for (int i = 0; i < p2; i++) {
        cin >> p;
        isPresent[p] = true;
    }

    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (!isPresent[i]) {
            cout << "Oh, my keyboard!";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "I become the guy." << endl;
    }

    return 0;
}
