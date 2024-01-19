t = int(input())
cpp_list = []
while t > 0:
    n = int(input())
    cpp_list = list(map(int, input().split()))
    cpp_list.sort()
    cpp_is_valid = True
    for i in range(1, len(cpp_list)):
        if cpp_list[i] != cpp_list[i - 1] + 1 and cpp_list[i] != cpp_list[i - 1]:
            cpp_is_valid = False
            break
    if cpp_is_valid:
        print("YES")
    else:
        print("NO")
    t -= 1
