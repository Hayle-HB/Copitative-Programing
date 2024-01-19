#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int> &nums) {
    vector<int> ans;

    int left = 0, right = 2;
    while(right < nums.size()){
      if(nums[left] != nums[right]){
        ans.push_back(nums[left]);
      }
      left++;
      right ++;
    }
    
    ans.push_back(nums[left++]);
    ans.push_back(nums[left]);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8};
    vector<int> ans = removeDuplicates(nums);

    cout << "Modified Array: ";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}
