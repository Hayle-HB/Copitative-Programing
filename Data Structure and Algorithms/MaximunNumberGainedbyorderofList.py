nums = [11, 23, 34, 45, 100, 2, 122 , 19 , 0, 0]
NEW = [str(x) for x in nums]
for i in range(len(nums)):
    for j in range(i+1, len(nums)):
        if int(NEW[i] + NEW[j]) < int(NEW[j] + NEW[i]):
            temp = NEW[i]
            NEW[i] = NEW[j]
            NEW[j] = temp
for i in NEW:
  print(i, end= " ")
  
Max_NUM = "".join(NEW)
print("\nThe Maximum Number gained by ordering the List is " + Max_NUM)
  
  