def game_winner(n):
    if n % 3 == 0:
        return "First"
    elif n % 3 == 1:
        return "Second"
    else:
        return "First"

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        result = game_winner(n)
        print(result)

if __name__ == "__main__":
    main()
