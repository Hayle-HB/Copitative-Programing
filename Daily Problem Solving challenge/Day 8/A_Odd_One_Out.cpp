#include <iostream>
using namespace std;


int main(){

  int t;
  cin >> t;
  int a, b, c;
  while(t--){
    cin >> a >> b >> c;

    if( a != b ){
      if( a == c){
        cout << b << endl;
      }
      else {
        cout << a << endl;
      }
    }
    else {
      cout << c << endl;
    }
  }
  return 0;
}