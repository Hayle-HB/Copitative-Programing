#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::vector<int> result;

    for (int num : nums) {
        int index = abs(num) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> result1 = findDisappearedNumbers(nums1);

    std::cout << "Missing numbers for nums1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1, 1};
    std::vector<int> result2 = findDisappearedNumbers(nums2);

    std::cout << "Missing numbers for nums2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
