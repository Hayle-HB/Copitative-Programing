#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Check for empty arrays
        if (nums1.empty() && nums2.empty()) {
            cout << "Both input arrays are empty. Cannot calculate median." << endl;
            return 0.0; // Return 0 as a placeholder for an invalid result.
        }

        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, mid = (m + n + 1) / 2;

        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = mid - partitionX;
            
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxX <= minY && maxY <= minX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }

        cout << "Invalid input arrays." << endl;
        return 0.0; 
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    double median = solution.findMedianSortedArrays(nums1, nums2);

    if (median != 0.0) {
        cout << "Median of the two sorted arrays: " << median << endl;
    }

    return 0;
}
