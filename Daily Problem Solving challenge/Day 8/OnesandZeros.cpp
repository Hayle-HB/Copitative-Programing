#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      int countZeros = 0;
      int countOnes = 1;
      int total_one = 0;
      int total_zero = 0;
      int max = 0;
        for(size_t i =0; i  < strs.size(); i++){
          string current = strs[i];
          for(size_t j = 0; j < current.size(); j++){
            if(current[j] == '0'){
              countZeros++;
            }
            else {
              countOnes++;
            }
          }

          if( total_one + countOnes <= n && total_zero + countZeros <= m){
            max++;
            total_one += countOnes;
            total_zero += countZeros;
          }

          countOnes = 0, countZeros = 0;
        }
        return max;
    }
};

int main(){

  vector<string> str ={"10","0001","111001","1","0"};

  cout << Solution().findMaxForm(str, 4, 3);

  return 0;
}