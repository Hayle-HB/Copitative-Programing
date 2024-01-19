#include <iostream>
using namespace std;


#include <vector>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);

        for (int i = 1; i <= rowIndex; ++i) {
            long long val = (long long)result[i - 1] * (rowIndex - i + 1) / i;
            result[i] = static_cast<int>(val);
        }

        return result;
    }
};



int main(){

  int raw ;
  cin >> raw;
  vector<int> result;
  result = Solution().getRow(raw);
  
  for(int i : result){
    cout << i << " ";
  }
  
  return 0;
}
