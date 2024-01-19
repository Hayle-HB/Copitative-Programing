#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        for (int num : arr) {
            int frequency = count(arr.begin(), arr.end(), num);
            if (frequency == num) {
                return num;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << s.findLucky(arr) << endl;

    return 0;
}
