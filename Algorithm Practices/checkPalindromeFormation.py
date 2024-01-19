class Solution:
      

    
  def checkPalindromeFormation(self, a: str, b: str)->bool:
    for i in range(1, len(a)+1):
      a_pre = a[:i]
      a_suf = a[i:]
      b_pre = b[:i]
      b_suf = b[i:]
      def isPalindrome(s: str)-> bool:
        return s == s[::-1]
      if isPalindrome(a_pre + b_suf) or isPalindrome(b_pre + a_suf):
        return True
      
    return False
  
  
  
a = "abcdef"
b = "fedcba"

sol = Solution()

print(sol.checkPalindromeFormation(a, b))
  
  
  
      
      
