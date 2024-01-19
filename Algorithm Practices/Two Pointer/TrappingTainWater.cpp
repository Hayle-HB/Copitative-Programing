#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
      int trap(vector<int> height){
         if(height.size() < 3){
            return 0;
         }
         int left = 0, right = height.size()-1;
         int trappedWater = 0;
         int leftMax = 0, rightMax = 0;

         while( left < right){
            if(height[left] < height[right]){
               if(height[left] >= leftMax){
                  leftMax = height[left];
               }
               else {
                  trappedWater += leftMax - height[left];
               }
               left++;
            }
            else {
               if(height[right] >= rightMax){
                  rightMax = height[right];
               }
               else {
                  trappedWater += rightMax - height[right];
               }
               right--;
            }
         }

         return trappedWater;

      }
};



int main(){

   vector<int> height = {4,2,0,3,2,5};

   cout << Solution().trap(height);





   return 0;
}