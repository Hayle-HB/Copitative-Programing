mylist = []

lenght = int(input())

for _ in range(lenght):
    num = int(input())
    mylist.append(num)

print("Number befor Sorting:")

for nums in mylist:
    print(nums, end = " ")
  
    #Buble sort
for i in range(0, lenght-1):
    smallest  = i
    for j in range(i+1, lenght):
      if(mylist[j] < smallest):
        smallest = j
    temp = mylist[smallest]
    mylist[smallest] = mylist[i]
    mylist[i] = temp

print("\nNumber afer Selectoin sort")

for i in mylist:
  print(i, end = ' ')