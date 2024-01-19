def find_division(rating):
    if rating >= 1900:
        return "Division 1"
    elif 1600 <= rating <= 1899:
        return "Division 2"
    elif 1400 <= rating <= 1599:
        return "Division 3"
    else:
        return "Division 4"

def main():
    t = int(input())
    for _ in range(t):
        rating = int(input())
        division = find_division(rating)
        print(division)

if __name__ == "__main__":
    main()
