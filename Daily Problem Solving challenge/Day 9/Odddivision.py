def oddDivisior(num):
  if num % 2 != 0:
    return "YES"
  else: 
    for i in range(3, int(num**0.5), 2):
      if num % i ==0:
        return "YES"
  return "NO"
n = int(input())

while n > 0:
  num = int(input())
  ans =  oddDivisior(num)
  print(ans)
  n -= 1