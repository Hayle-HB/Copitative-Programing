def max_product(n, digits):
    min_digit = min(digits)
    min_index = digits.index(min_digit)
    
    # Increment the minimum digit by 1
    digits[min_index] += 1
    
    # Calculate the product of all digits
    product = 1
    for digit in digits:
        product *= digit
    
    return product

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        digits = list(map(int, input().split()))
        
        result = max_product(n, digits)
        print(result)

if __name__ == "__main__":
    main()
