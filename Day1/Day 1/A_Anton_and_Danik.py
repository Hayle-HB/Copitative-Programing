n = int(input())
results = input()

count_A = results.count('A')
count_D = results.count('D')

if count_A > count_D:
    print("Anton")
elif count_D > count_A:
    print("Danik")
else:
    print("Friendship")
