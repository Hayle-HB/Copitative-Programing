def count_vowels(word: str) -> str:
  count = 0
  word = word.lower()
  for i in range(len(word)):
    
    if word[i] == 'a' or word[i] == 'e' or word[i] == 'i' or word[i] == 'o' or word[i] == 'u':
      count += 1
  return count

word = str(input("Enter Word: "))

print("There is ", count_vowels(word) , " vowels vaule is the word")