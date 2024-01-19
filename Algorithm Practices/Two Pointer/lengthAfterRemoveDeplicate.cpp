#include <iostream>
using namespace std;
#include <vector>

int lengthAfterRemoveDuplicate(vector<int> nums){
    if(nums.empty()){
        return 0;
    }

    int slow = 0;
    
    for (int fast = 1; fast < nums.size(); fast++){
        if(nums[fast] != nums[slow]){
            ++slow;
            nums[slow] = nums[fast];
        }

    }

    return slow + 1;

}


int main(){

    vector<int> nums = {1, 2, 2, 3, 4, 5, 5, 5, 6};

    cout <<"After Deleting: " <<  lengthAfterRemoveDuplicate(nums);



    return 0;
}