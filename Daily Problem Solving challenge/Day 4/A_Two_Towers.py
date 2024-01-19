def is_beautiful_pair(n, m, tower1, tower2):
    # Check if the towers are already beautiful
    if tower1[-1] != tower2[-1]:
        return "YES"
    
    # Check if it's possible to make the towers beautiful by moving blocks
    if 'R' in tower1 and 'B' in tower2:
        return "YES"
    elif 'B' in tower1 and 'R' in tower2:
        return "YES"
    else:
        return "NO"

def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        tower1 = input().strip()
        tower2 = input().strip()
        
        result = is_beautiful_pair(n, m, tower1, tower2)
        print(result)

if __name__ == "__main__":
    main()
