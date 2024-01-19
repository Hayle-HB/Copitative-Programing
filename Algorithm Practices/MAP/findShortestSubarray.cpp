#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findShortestSubarray(const vector<int>& nums) {
    unordered_map<int, int> freq, firstOccurrence;
    int degree = 0, minLength = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
        freq[nums[i]]++;
        if (firstOccurrence.find(nums[i]) == firstOccurrence.end()) {
            firstOccurrence[nums[i]] = i;
        }

        if (freq[nums[i]] > degree) {
            degree = freq[nums[i]];
            minLength = i - firstOccurrence[nums[i]] + 1;
        } else if (freq[nums[i]] == degree) {
            minLength = min(minLength, i - firstOccurrence[nums[i]] + 1);
        }
    }

    return minLength;
}

int main() {
    // Example 1
    vector<int> nums1 = {1, 2, 2, 3, 1};
    cout << "Example 1: " << findShortestSubarray(nums1) << endl; // Output: 2

    // Example 2
    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};
    cout << "Example 2: " << findShortestSubarray(nums2) << endl; // Output: 6

    return 0;
}
