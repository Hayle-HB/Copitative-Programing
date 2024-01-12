#include <iostream>
using namespace std;

class Solution {
public:
    int isPalindrome(int x) {
       if(x < 0 ){
        return false;
       }

       int temp = x;
       int rev = 0;
       while(x!=0){
        rev = rev * 10 + x % 10;
        x /= 10;
       }

       return rev == temp;
        
    }
};


int main(){
int x;
cin >> x;
cout << Solution().isPalindrome(x) << endl;

  return 0;
}