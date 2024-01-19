x1, x2, x3, x4 = map(int, input().split())

max_val = max(x1, x2, x3, x4)
My_list = [x1, x2, x3, x4]
My_list.remove(max_val)
a = max_val - My_list[0]
b = max_val - My_list[1]
c = max_val - My_list[2]

print(a, b, c)
My_list.clear()
