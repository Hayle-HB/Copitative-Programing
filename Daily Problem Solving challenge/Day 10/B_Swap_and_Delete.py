test = int(input())
while test > 0:
  test -= 1
  good = str(input())
  zero = 0
  one = 0
  for i in range(len(str)):
    if str[i] == "0":
      zero += 1
    else: 
      one += 1
  if zero == one:
    print(0)
    continue
  else:
    print(abs(zero-one))