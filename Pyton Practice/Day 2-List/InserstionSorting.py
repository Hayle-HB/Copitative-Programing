mylist = []
list_length = int(input())

# Input numbers into the list
for _ in range(list_length):
    num = int(input())
    mylist.append(num)

# Display the numbers before sorting
print("Numbers before Sorting:")
for i in mylist:
    print(i, end=" ")

#insersion Sort
for i in range(1, list_length):
    key = mylist[i]
    j = i - 1
    while j >=0 and key < mylist[j]:
        mylist[j+1] = mylist[j]
        j = j - 1
    mylist[j+1] = key
# Display the numbers after sorting
print("\nNumbers after Sorting:")
for i in mylist:
    print(i, end=" ")
