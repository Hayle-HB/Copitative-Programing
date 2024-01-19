#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int len = grid.size();
        const int size = len * len + 1;
        int* check = new int[size]();  // Initialize the array to zero
        int sum = 0;
        int max = grid[0][0];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                sum += grid[i][j];
                if(grid[i][j] > max){
                  max = grid[i][j];
                }
                check[grid[i][j]]++;
                if (check[grid[i][j]] == 2) {
                    ans.push_back(grid[i][j]);
                }
            }
        }

        delete[] check;  // Use delete[] to delete the array

        len = len * len;
        int expct = (len * (len + 1)) / 2;
        sum = sum - ans[0];
        if(expct - sum == 0){
          ans.push_back(max + 1);
        }
       else { 
        if(sum < expct ){
        ans.push_back(expct - sum); 
         }
        else {
          ans.push_back(sum - expct);
        }
       }
        return ans;
    }
  
};



int main(){
  vector<vector<int>> val ={
          {9, 1, 7},
          {8, 9, 2},
          {3, 4, 6}
  };
  vector<int> ans = Solution().findMissingAndRepeatedValues(val);
  cout << ans[0] << "  " << ans[1];


  return 0;
}