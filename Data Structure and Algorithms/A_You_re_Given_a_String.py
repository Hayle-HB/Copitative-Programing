def longest_repeated_substring(s):
    n = len(s)
    max_length = 0

    for i in range(n):
        for j in range(i + 1, n):
            length = 0
            while j + length < n and s[i + length] == s[j + length]:
                length += 1

            if length > 0 and length > max_length:
                max_length = length

    return max_length

input_string = input().strip()

result = longest_repeated_substring(input_string)
print(result)
