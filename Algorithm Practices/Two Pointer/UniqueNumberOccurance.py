arr = [1 , 2, 2, 3, 4, 4, 5, 5]
nums = []

for i in arr:
  if i not in nums:
    nums.append(i)
print(nums)
c = [arr.count(i) for i in nums]
print(c)
d = []
for i in c:
  if i not in d:
    d.append(i)
print(d)
for i in d:
  if nums.count(i) != 1:
    print("NOT Unique "  ,i)
  else:
    print(i, " is Unique ")
print(nums)
print(arr)