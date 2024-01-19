t = int(input())

while t > 0:
    try:
        num = int(input())
    except EOFError:
        break  

    len2 = str(num)
    length = len(len2)
    
    for i in len2:
        if i == "0":
            length -= 1
            
    print(length)
    
    exp = 1
    while num > 0:
        rem = int((num % 10) * exp)
        if rem != 0:
            print(rem, end=" ")
        exp *= 10
        num = int(num / 10)

    t -= 1
    print()
