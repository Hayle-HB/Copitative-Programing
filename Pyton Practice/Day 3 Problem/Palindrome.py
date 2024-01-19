def is_palindrome(s):
    new_str = s.replace(" ", "").lower()

    return new_str == new_str[::-1]


test = int(input())
try:
    while test > 0:
        test -= 1
        Word  = str(input())
        if is_palindrome(Word):
            print(Word, "is palindrome ")
        else: print(Word, "is not palindrome")
except EOFError:
    print("Invalid input ")