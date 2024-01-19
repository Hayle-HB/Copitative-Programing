def is_Planedrome(word: str) -> bool:
  for i in range(len(word)):
    if word[i] != word[len(word)-1-i]:
      return False
  return True


word = str(input("Enter the word: "))

if(is_Planedrome(word)):
  print(word, "is a planedrome")
else:
  print(word, "is not a planedrome")
  