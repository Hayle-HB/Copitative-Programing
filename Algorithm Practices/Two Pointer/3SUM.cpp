#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
      vector<vector<int>> ThreeSum0(vector<int> list){
         vector<vector<int>> ans;
         if(list.size() < 3){
            return ans;
         }
         sort(list.begin(), list.end());

         for (int i = 0; i < list.size()-2; i++){
            if( i > 0 && list[i] == list[i-1]){
               continue;
            }

            int left = i+1, right =list.size()-1;
            int target = -list[i];

         while(left < right){
            if(list[left] + list[right] == target){
                  ans.push_back({list[i], list[left], list[right]});
               

               while(left < right && list[left] == list[left +1]){
                  left++;
               }
               while(left < right && list[right] == list[right-1]){
                  right--;
               }
               right--;
               left++;            
            }
            else if(list[left] + list[right] < target){
               left++;
            }
            else {
               right--;
            }
         }
         }
         return ans;
      }
};



int main(){
   vector<int> xxx = {-1,0,1,2,-1,-4};
   vector<vector<int>> num = Solution().ThreeSum0(xxx);

   for(vector<int> i : num){
      for (int j : i){
         cout << j << " ";
      }
   }


   return 0;
}