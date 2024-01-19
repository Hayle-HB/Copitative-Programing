def min_seconds_to_lineup(n, heights):
    max_height_index = heights.index(max(heights))
    min_height_index = heights[::-1].index(min(heights))

    if max_height_index + min_height_index >= n:
        return max_height_index + min_height_index - 1
    else:
        return max_height_index + min_height_index


def main():
    n = int(input())
    heights = list(map(int, input().split()))

    result = min_seconds_to_lineup(n, heights)
    print(result)


if __name__ == "__main__":
    main()
