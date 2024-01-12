#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            if (numSet.count(num) == 0) {
                numSet.insert(num);
            } else {
                numSet.erase(num);
            }
        }
        return *numSet.begin();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.singleNumber(nums);

    return 0;
}
