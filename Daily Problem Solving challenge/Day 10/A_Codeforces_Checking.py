def check_codeforces(char):
    codeforces_str = "codeforces"

    if char in codeforces_str:
        return "YES"
    else:
        return "NO"

def main():
    t = int(input())

    for _ in range(t):
        char = input().strip()
        result = check_codeforces(char)
        print(result)

if __name__ == "__main__":
    main()
