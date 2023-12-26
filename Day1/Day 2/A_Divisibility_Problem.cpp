#include <iostream>
using namespace std;

int main(){

  int n, a , b;
  cin >> n;
  int move = 0;

  while(n--){
    cin >> a >> b;
    while (a % b != 0){
      move++;
       a++;
  }

  cout << move << endl;
  move = 0;
  }
  return 0;
}