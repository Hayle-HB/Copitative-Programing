#List buildin Methods

list = []

# .append(data) used to add data to the list

list.append(8)
list.append(2)
list.append(7)
list.append(4)
list.append(0)
list.append(1)

for i in list:
  print(i , end = '  ')

# .extend(list) used to add a list to a list iteratively
print()
list.extend([6, 7, 7, 7, 10])

for i in list:
  print(i , end = '  ')


# .insert(data, index) used to insert data at the given index
print()
list.insert(0, "Hayle Mark")

for i in list:
  print(i , end = '  ')
  
  # .remove(index) used to remove data at the given index
  
list.remove(1)
print()
for i in list:
  print(i , end = '  ')


pop = list.pop(0)

print("\nPoped: " , pop)

# .index(x[ start, end ]) used to find the index of the value x form the lsit

index = list.index(6)

print(index , " is the index of the value 2 ")


num = list.count(7)

print("There is " , num , ": \"7\" in the list")


# .sort(key, reverse=True) used to sort the list by key either assending or dessending order

list.sort()

for i in list:
  print(i , end = '  ')
  
list.sort(reverse = True)

print()

for i in list:
  print(i , end = '  ')
  
  
vegitable = ["apple", "strawberry", "banana", "orange", "floral"]

#sort using the key value

vegitable.sort(key = len)
print()
for i in vegitable:
  print(i, end =' ')
  