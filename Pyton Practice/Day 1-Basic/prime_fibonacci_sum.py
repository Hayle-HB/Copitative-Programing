import math

def prime_fibonacci_sum(num: int) -> int:
    first = 0
    second = 1
    next = first + second
    sum = next
    while next < num:
        next = first + second
        if prime(next):
            sum += next
        first = second
        second = next
    return sum

def prime(num):
    if num == 0 or num == 1:
        return False
    if num == 2:
        return True
    for i in range(3, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

print(prime_fibonacci_sum(5))
