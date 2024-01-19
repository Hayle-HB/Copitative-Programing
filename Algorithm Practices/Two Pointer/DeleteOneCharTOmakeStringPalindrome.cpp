#include <iostream>
using namespace std;
bool isPalindrome(string str, int left, int right){
    while(left <= right){
        if(str[left] != str[right]){
        return false;
        }
          return true;
    }    
}

bool CanAPalindromeFormByDeletaingOneCharacter(string str){
     int left = 0, right = str.length()-1;
    while( left <= right){
        if(str[left] != str[right]){
            return isPalindrome(str, left+1, right) || isPalindrome(str, left, right - 1);
        }
        left++;
        right--;
    }
        return true;
}






int main(){
    
    string str = "aaabbbaaa";
    if(CanAPalindromeFormByDeletaingOneCharacter(str)){
         cout << "Yes, We can create a string palindrome by deleting at most one character " << endl;
    }
   else {
            cout << "No we can't create a string by deleting only one character  " << endl;
   }
    

return 0;
}