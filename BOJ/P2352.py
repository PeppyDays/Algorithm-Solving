from bisect import bisect_left

N = int(input())
Lis = []

for port in [int(_) for _ in input().split()]:
    idx = bisect_left(Lis, port)
    if idx >= len(Lis):
        Lis.append(port)
    else:
        Lis[idx] = port

print(len(Lis))
