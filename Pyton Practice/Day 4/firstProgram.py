def sumOfEvenNumber(mylist: list) -> int:
  sum = 0
  for i in mylist:
    if i % 2 == 0:
      sum += i
  return sum


def sumOfEvenNumbers(mylist: list) -> int:
  return sum(num for num in mylist if num % 2 == 0)

mylist = []
for i in range(5):
  mylist.append(int(input()))
    
print("Sum: ", sumOfEvenNumber(mylist))
print("Sums: ", sumOfEvenNumbers(mylist))