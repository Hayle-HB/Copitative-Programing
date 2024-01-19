#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        string binary ="";
        while(num != 0){
            int bit =  num % 2;
            num /=2;
            if(bit == 0){
                binary = "1" + binary;
            }
            else {
              binary = "0" + binary;
            }
        }
        int result = 0;
        for(int i = binary.length()-1; i >=0 ; i--){

          if( binary[i] == '1'){
            result += pow(2,binary.length()-i-1);
          }
          
        }
        return result;
        
    }
};

/*
more efficient implementation:
class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int bitPosition = 0;

        while (num > 0) {
            int bit = num % 2;
            num /= 2;

            int complementBit = (bit == 0) ? 1 : 0;

            result += complementBit << bitPosition;
            bitPosition++;
        }

        return result;
    }
};
*/


int main(){
  int n;
  cin >> n;

  while(n--){
    int x;
    cin >> x;
    cout << Solution().findComplement(x) << endl;
  }



  return 0;
}