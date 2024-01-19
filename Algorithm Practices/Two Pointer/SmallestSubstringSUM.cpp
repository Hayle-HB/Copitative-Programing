#include <iostream>
using namespace std;
#include <vector>

int samllestSubstringLen(vector<int> nums, int targetd){


  int sum = 0;
  int minLen = INT_MAX;

  int left = 0, right = 0;

  while(right < nums.size()){
    sum += nums[right];
    while( sum >= targetd){
      minLen = min(minLen, right-left+1);
      sum -= nums[left];
      left++;
    }
    right++;
  }

  return minLen == INT_MAX ? 0 : minLen;
}

int main(){

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 21;
    int result = samllestSubstringLen(nums, target);
    cout << result << endl;  // Output: 2


  return 0;
}