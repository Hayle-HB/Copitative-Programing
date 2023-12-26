#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        return (n & (n - 1)) == 0;
    }
};


int main() {

  int n;
  cin >> n;
  int x;

  for(int i =0; i < n; i++){
    cin >> x;
    if(Solution().isPowerOfTwo(x)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  


    return 0;
}
