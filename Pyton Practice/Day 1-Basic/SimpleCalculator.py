def addtion(num1: int, num2: int) -> int:
  return num1 + num2
  
  
def substraction(num1: int, num2: int) -> int:
  return num1 - num2


def multiplication(num1: int, num2: int) -> int:
  return num1 * num2

def divison(num1: int, num2: int) -> float:
  return num1 / num2

num1 = int(input("Enter numb 1: "))
num2 = int(input("Enter numb 2: "))

while True:
  
  print("""
        1. Addition
        2. Substraction
        3. Multiplication
        4. Division
        5. Exit
        """)
  aaa = int(input("Enter your choice: "))


  if aaa == 1:
    print("The addtion of the two number is ", addtion(num1, num2))
  elif aaa == 2:
    print("The substraction of the two number is ", substraction(num1, num2))
  elif aaa == 3:
    print("The multiplication of the two number is ", multiplication(num1, num2))
  elif aaa == 4:
    print("The division of the two number is ", divison(num1, num2))
  elif aaa == 5:
        break
  else:
    print("Wrong choice")
    