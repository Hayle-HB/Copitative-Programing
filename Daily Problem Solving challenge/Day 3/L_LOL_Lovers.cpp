#include <iostream>
using namespace std;


int main(){

  int n;
  cin >> n;

  string lol;
  cin >> lol;
  int k =1;
  int l1 = 0, l2 = 0, o1 = 0, o2 = 0;
  bool found = false;


  while( k != n ){

    for(int i=0; i< k ; i++){
        if(lol[i] == 'L'){
          l1++;
        }
        else {
          o1++;
        }
  }

  for(int j = n-1;  j >= k; j--){
    if(lol[j] == 'O'){
      o2++;
    }
    
    else {
      l2++;
    }
  }
  

  if(o1 !=o2 && l1 != l2){
    cout << k;
    found = true;
    break;
  }

  else {
    l1 = 0, l2 = 0, o1 = 0, o2 = 0;
  }
    
  k++;
}
      

    if(!found){
      cout << -1 ;
    }

  return 0;
}
