x, y, w, h = [int(v) for v in input().split()]
print(min([x, w - x, y, h - y]))
