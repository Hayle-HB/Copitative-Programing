#include <iostream>
using namespace std;

int numberOfBill(int n){

  int total = 0;
  while(true){
    if( n - 100 >= 0){
      n -= 100;
      total += 1;
    }
    else if( n - 20 >= 0){
      n -= 20;
      total += 1;
    }
    else if( n - 10 >= 0){
      n -= 10;
      total += 1;
    }
    else if( n - 5 >= 0){
      n -= 5;
      total += 1;
    }
    else if( n - 1 >= 0){
      n -= 1;
      total += 1;
    }
    else {
      break;
    }
  }
    return total;

}

int main(){


  int n;
  cin >> n;
  cout << numberOfBill(n) << endl;



  return 0;
}