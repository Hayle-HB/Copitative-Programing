horseshoes = list(map(int, input().split()))

unique_colors = len(set(horseshoes))

needed_horseshoes = max(0, 4 - unique_colors)

print(needed_horseshoes)
