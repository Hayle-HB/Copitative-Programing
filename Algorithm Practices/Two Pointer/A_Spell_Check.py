t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    m = str(input())
    
    
    new_str = ''.join(sorted(m))
    
    if len(new_str)!= 5:
        print("NO")

    elif new_str[0] == "T" and new_str[1] == "i" and new_str[2] == "m" and new_str[3] == "r" and new_str[4] == "u":
        print("YES")
    else:
        print("NO")