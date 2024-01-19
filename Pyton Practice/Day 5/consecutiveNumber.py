def consecutiveLists(my_list):
    my_list.sort()
    max_length = 1
    current_length = 1

    for i in range(1, len(my_list)):
        if my_list[i] == my_list[i-1] + 1:
            current_length += 1
        else:
            if current_length > max_length:
                max_length = current_length
            current_length = 1

    if current_length > max_length:
        max_length = current_length

    return max_length

my_list = [1, 3, 4, 2, 5, 6, 7]
print(consecutiveLists(my_list))
