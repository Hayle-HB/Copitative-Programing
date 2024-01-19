#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return canFormPalindrome(a, b) || canFormPalindrome(b, a);
    }
    
    bool canFormPalindrome(const string& s1, const string& s2) {
        int i = 0, j = s1.length() - 1;
        
        while (i < j && s1[i] == s2[j]) {
            i++;
            j--;
        }
        
        return isPalindrome(s1, i, j) || isPalindrome(s2, i, j);
    }

    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string a = "xbdef";
    string b = "xecab";
    
    cout << Solution().checkPalindromeFormation(a, b);

    return 0;
}
