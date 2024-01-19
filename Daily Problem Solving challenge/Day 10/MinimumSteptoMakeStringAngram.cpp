#include <iostream>
using namespace std;


int main(){

  string s = "leetcode";
  string t ="coats";

  int* ans = new int[26];
  for(int i =0; i < 26; i++){
    ans[i] = 0;
  }
  for(int i =0; i < s.length(); i++){
    ans[s[i] - 'a']++;
  };
    for(int i =0; i < t.length(); i++){
    ans[t[i] - 'a']--;
  };
    int total = 0;
  for(int i =0; i < 26; i++){
      cout << ans[i] <<"  ";
  }

  for(int i =0; i < 26; i++){
      if(ans[i] < 0){
        total += -ans[i];
      }
      else {
        total += ans[i];
      }
  }

  delete[] ans;

  cout << "\nTotal step to make \"t\" Angram :  " << total;
  return 0;
}