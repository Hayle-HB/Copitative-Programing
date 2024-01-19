string_input = input("Enter number separated by spaces: \n")

separeted_value = string_input.split()

myList = [num for num in separeted_value]

for i in range(len(myList)):
  print(myList[i] , end=" ")