#include <iostream>
using namespace std;

bool luckyNumber(int n){
  int rem = 0;
  while(n!=0) {
    rem = n%10;
    if(rem != 4 && rem != 7){ 
      return false;
          break;
    }
    n = n/10;
  }
  return true;
}

bool divisibleBy(int n){
  
    for(int i =4; i <= n/2; i++){
    if(luckyNumber(i)){
      if(n%i == 0){
        return true;
        break;
        }
      }
    }
    return false;

}
int main(){

  int n;
  cin >> n;
   
   if(luckyNumber(n)){
    cout << "YES" << endl;
   }
   else if(divisibleBy(n)){
    cout << "YES" << endl;
   }
   else {
    cout << "NO" << endl;
   }


}