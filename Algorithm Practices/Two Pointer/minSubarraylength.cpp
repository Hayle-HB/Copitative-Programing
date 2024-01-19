#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumSubArrayLength(vector<int> nums, int K){
    int sum = 0;
    int minLen = INT_MAX;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right){
        sum += nums[right];

        while( sum >= K){
            minLen = min(minLen, right-left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return minLen == INT_MAX ? 0: minLen;
}


int main(){

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Min Length is : " << minimumSubArrayLength(nums, 16);


return 0;
}