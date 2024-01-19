my_list = ["I", "am", "not", "a", "good", "person", "but", "that", "does", "not", "make", "me", "a", "bad", "guy!"]

print(my_list[:])
print()
print(my_list[0:6])
print()
print(my_list[7:])
print(my_list[-4:-1])
my_list[2:6] = ["not", "a", "bad", "person"]
my_list[-3:-1] = ["a", "good"]
print()
print(my_list)
del my_list[1]
print()
print(my_list)


another_list = ["aaa", "aba", "bbb", "ccc", "cac"]

newList = [a for a in another_list if 'a' in a]

print(newList)



LIST =[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

sqare = [x**2 for x in LIST if x % 2 == 0]

print(sqare)


def myfunc(n):
  return abs(n - 50)

thislist = [100, 50, 65, 82, 23]
thislist.sort(key = myfunc)
print(thislist)



def custom_sort_criteria(word):
    # This function returns the last character of each word
    return word[-1]

words = ["apple", "banana", "kiwi", "orange", "grape"]

# Sort the list of words based on the custom criteria function
sorted_words_custom = sorted(words, key=custom_sort_criteria)

# Print the result
print("Sorted words based on custom criteria:", sorted_words_custom)
