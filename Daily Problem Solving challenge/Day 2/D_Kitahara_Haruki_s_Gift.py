n = int(input())
weights = list(map(int, input().split()))

count_100 = weights.count(100)
count_200 = n - count_100 

if count_100 % 2 == 0 and (count_200 % 2 == 0 or count_100 > 0):
    print("YES")
else:
    print("NO")
