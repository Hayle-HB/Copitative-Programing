#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int left = 0;
        int right  = arr.size()-1;
        int added = 0;
        
        while(left < right){
            if(arr[left] == 0){
                arr.insert(arr.begin() + left, 0);
                added++;
                left++;
            }
            if(arr[right] == 0){
                arr.insert(arr.begin() + right, 0);
                added++;
                right--;
            }
            left++;
            right--;
        }
        while(added--){
            arr.erase(arr.end()-1);
        }
    }
};

int main(){

    vector<int> arr = {1,0,2,3,0,4,5,0};
    
    Solution().duplicateZeros(arr);

    for(int i: arr){
        cout << i << "  ";
    }

}



