#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n;
      cin >> n;

      vector<int> cpp_list(n);
        for (int i = 0; i < n; ++i) {
          cin >> cpp_list[i];
        }

      sort(cpp_list.begin(), cpp_list.end());

        bool cpp_is_valid = true;
        for (int i = 1; i < n; ++i) {
            if (cpp_list[i] != cpp_list[i - 1] + 1 && cpp_list[i] != cpp_list[i - 1]) {
                cpp_is_valid = false;
                break;
            }
        }

        if (cpp_is_valid) {
          cout << "YES" <<endl;
        } else {
          cout << "NO" <<endl;
        }

        --t;
    }

    return 0;
}
