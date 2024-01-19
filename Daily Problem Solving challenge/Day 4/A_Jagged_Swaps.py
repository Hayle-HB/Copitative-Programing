Num = int(input("Enter a number"))
if Num == 0: 
    print(0)
if Num < 0:
    negative = True
else: negative = False

num = []
while Num > 0:
    rem = Num % 10
    num.append(rem)
    Num //=10

if not negative:
   x =  num.reverse()
else: 
    x = num.reverse(reverse=True)



print(x)
    