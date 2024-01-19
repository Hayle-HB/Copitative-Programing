def is_distinct(year):
    return len(set(str(year))) == len(str(year))

def find_next_distinct_year(current_year):
    next_year = current_year + 1
    while not is_distinct(next_year):
        next_year += 1
    return next_year


y = int(input().strip())


result = find_next_distinct_year(y)
print(result)
