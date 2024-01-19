#include <iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
      int temp = 1;
      int Monday = 1;
      int weekDay = 0;
      int totalDays = 0;
      int Money = 0;

      while(true){
        if(n - 7 >=0){
          weekDay = 7;
        }
        
        else{
          weekDay = n;
        }
        if(weekDay <= 0){
          break;
        }
        temp = Monday;
        Money += temp;
        for(int i = 1; i < weekDay; i++){
          Money += ++temp;
        }
        n -= weekDay;
        Monday++;
      }
      return Money;
        
    }
};


int main(){

    int n;
    cin >> n;
  cout << Solution().totalMoney(n) << endl;



  return 0;
}