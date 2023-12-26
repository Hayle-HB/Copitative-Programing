def amount_to_borrow(k, n, w):
    total_cost = (w * (2 * k + (w - 1) * k)) // 2 
    borrow_amount = max(0, total_cost - n) 
    return borrow_amount

k, n, w = map(int, input().split())

result = amount_to_borrow(k, n, w)
print(result)
