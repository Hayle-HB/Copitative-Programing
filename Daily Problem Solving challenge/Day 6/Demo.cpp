#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void count(string& str){
  sort(str.begin(), str.end());

  for(char i : str){
    cout << i;
  }
  cout << endl;
  for(int i = 1; i <= 12; i++){
    cout << i;
  }
   int begin= str.size()-str.size()/3;
  char current = str[begin-1];
  int total = 1;

  for(int i = begin; i < str.size()-2; i++){
    if(str[i] != current && str[i] > 'a' && str[i] < 'z'){
      total++;
      current = str[i];
    }
  }

  cout << endl <<  total + 1 << endl;

}


int main(){


  string str = "{a, a, a, a}";

  count(str);



  return 0;
}









