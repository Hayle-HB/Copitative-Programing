#include <iostream>
#include <algorithm>
using namespace std;



int main(){

  int n;
  cin >> n;
  int one = 0;
  int two = 0;
  int three = 0;
  int num;
  for(int i = 0; i < n;i++){
    cin >> num;
    if(num == 1){
      one++;
    }
    else if(num == 2){
      two++;
    }
    else if(num == 3){
      three++;
    }
  }
  int Max = max(max(one,two),three);
  cout << n - Max << endl;
  return 0;
}