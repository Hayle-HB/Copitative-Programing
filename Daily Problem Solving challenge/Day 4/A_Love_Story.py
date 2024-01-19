def count_differences(s):
    target = "codeforces"
    diff_count = 0

    for i in range(10):
        if s[i] != target[i]:
            diff_count += 1

    return diff_count

def main():
    t = int(input())
    for _ in range(t):
        s = input()
        result = count_differences(s)
        print(result)

if __name__ == "__main__":
    main()
