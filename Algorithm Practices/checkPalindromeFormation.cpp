#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {

        for(int i =0; i <= a.length(); i++){
            string a_pre = a.substr(0, i);
            string a_suf = a.substr(i);
            string b_pre = b.substr(0, i);
            string b_suf = b.substr(i);

            if(Palindrome(a_pre + b_suf) || Palindrome(b_pre + a_suf)){
                return true;
            } 
        }
        return false;
            
    }
    
    bool Palindrome(string str){
            for(int i =0; i < str.length(); i++){
                if(str[i] != str[str.length()-i-1]){
                    return false;
                }
                return true;
            }
    }
        
};



int main(){


    string a = "ulacfd", b = "jizalu";
    cout << Solution().checkPalindromeFormation(a, b);




    return 0;
}