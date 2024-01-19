#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> even;
        vector<int>odd;

        for(int I: nums){
          if(I == 0 || I == 1){
            even.push_back(I);
            odd.push_back(I);
          }
          else if( I % 2 == 0){
            bool is_valid = true;
            for(int i =0; i < even.size(); i++){
              if( I % even[i] != 0 || even[i] % I != 0){
                is_valid = false;
                break;
              }
            }
            if(is_valid){
            even.push_back(I);
            }

          }
          else {
            bool is_valid = true;
            for(int i =0; i < odd.size(); i++){
              if( I % odd[i] != 0 || odd[i] % I != 0){
                is_valid = false;
                break;
              }
            }
            if(is_valid){
            odd.push_back(I);
            }
        }
        }
      return (even.size() > odd.size()) ? even : odd;
    }
};



int main(){

  vector<int> nums = {1, 2, 3, 4, 5, 6};

  vector<int>ans = Solution().largestDivisibleSubset(nums);
  for(int I : ans){
    cout << I << " ";
  }



  return 0;
}