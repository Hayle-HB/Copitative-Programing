#include <iostream>
using namespace std;

bool findSum(int x, int y, int sum){
  return x + y == sum;
}


int main(){

  int n;
  cin >> n;

  while(n--){
    int x, y , z;
    cin >> x >> y >> z;

    if(findSum(x, y, z)){
      cout << "YES" << endl;
    continue;
        }
    else if(findSum(x, z, y)){
      cout << "YES" << endl;
      continue;
    }
    else if(findSum(y, z, x)){
      cout << "YES" << endl;
      continue;
          }
    else {
      cout << "NO" << endl;
      continue;
      }
  }



  return 0;
}