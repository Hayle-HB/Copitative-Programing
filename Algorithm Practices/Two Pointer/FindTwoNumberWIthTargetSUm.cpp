#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

vector<int> findTwoNumbers(vector<int> nums, int target){
  int left = 0, right = nums.size()-1;
  sort(nums.begin(), nums.end());
  int sum = 0;
    while(left < right){
      sum = nums[left] + nums[right];
      if(sum == target){
        return {nums[left] , nums[right]};
      }
      else if( sum < target){
        left++;
      }
      else {
        right--;
      }
    }

    cout << "No element is found " << endl;

}


int main(){

  vector<int> nums = {7, 2, 3, 4, 5, 6, 7, 8};

  vector<int> ans = findTwoNumbers(nums, 14);
  cout << ans[0]  << "  "  << ans[1];



  return 0;
}