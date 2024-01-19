def reverseWord(word: str) -> str:
  newWord = ""
  for i in range(len(word)-1, -1, -1):
    newWord += word[i]
    
  return newWord


word = str(input("Enter the word: "))
print("The reverse of " + word + " is " + reverseWord(word))