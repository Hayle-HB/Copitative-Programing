def is_Palindrome(word):
  for i in range(len(word)):
    if word[i] != word[len(word) - i - 1]:
      return False
  return True

def PalindromeWords(lists):
  answer = [word for word in lists if is_Palindrome(word.lower())]
  return answer


list = ["Radar", "AABBAA", "amen", "youoy"]

print(PalindromeWords(list))