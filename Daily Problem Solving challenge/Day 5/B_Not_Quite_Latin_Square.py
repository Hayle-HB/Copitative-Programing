def find_missing_letter(latin_square):
    for i in range(3):
        if '?' in latin_square[i]:
            missing_letter = set('ABC') - set(latin_square[i])
            return missing_letter.pop()
        
        column = [latin_square[j][i] for j in range(3)]
        if '?' in column:
            missing_letter = set('ABC') - set(column)
            return missing_letter.pop()

t = int(input().strip())

for _ in range(t):
    latin_square = [input().strip() for _ in range(3)]
    
    result = find_missing_letter(latin_square)
    print(result)
