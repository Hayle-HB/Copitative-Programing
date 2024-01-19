class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        Vowel = 0
        vowels = set("aeiouAEIOU")

        for i in range(0, len(s) // 2):
            if s[i] in vowels:
                Vowel += 1

        for i in range(len(s) // 2, len(s)):
            if s[i] in vowels:
                Vowel -= 1

        return Vowel == 0
      
s = "HaylemeskelHaylemariam"
sol = Solution()
if sol.halvesAreAlike(s):
  print(s, " is alike")
else:
  print(s, " isn't alike ")