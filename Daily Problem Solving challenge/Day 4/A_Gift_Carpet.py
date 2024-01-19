def vika_likes_carpet(t, test_cases):
    results = []
    
    for _ in range(t):
        n, m = test_cases[_][0], test_cases[_][1]
        carpet = [input() for _ in range(n)]

        found_columns = [False] * 4

        for col in range(m):
            if carpet[0][col] == 'v':
                found_columns[0] = True
            elif carpet[0][col] == 'i' and found_columns[0]:
                found_columns[1] = True
            elif carpet[0][col] == 'k' and found_columns[1]:
                found_columns[2] = True
            elif carpet[0][col] == 'a' and found_columns[2]:
                found_columns[3] = True

        if all(found_columns):
            results.append("YES")
        else:
            results.append("NO")

    return results

if __name__ == "__main__":
    t = int(input())
    test_cases = []

    for _ in range(t):
        n, m = map(int, input().split())
        carpet = [input() for _ in range(n)]
        test_cases.append((n, m, carpet))
    
    results = vika_likes_carpet(t, test_cases)
    
    for res in results:
        print(res)
