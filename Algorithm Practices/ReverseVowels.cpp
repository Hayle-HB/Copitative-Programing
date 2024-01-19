
#include <iostream>
using namespace std;

class Solution {
    public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length()-1;
        
        while(left < right){
            
            if(is_vowels(s[left]) && is_vowels(s[right])){
                char ch = s[left];
                s[left] = s[right];
                s[right] = ch;
                left++;
                right--;
            }
            
            else if(is_vowels(s[left])){
                right--;
            }
            else if(is_vowels(s[right])){
                left++;
            }
            else {
                left++;
                right--;
            }
            
        }
        return s;
    }
    
    bool is_vowels(char ch){
        return ch == 'a' || ch == 'A' || ch == 'E' || ch == 'e' || ch == 'i' || ch == 'I' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u';
    }
};


int main(){

    string name = "Leetcode";
    cout << Solution().reverseVowels(name);

    cout << endl << Solution().is_vowels('I');
}