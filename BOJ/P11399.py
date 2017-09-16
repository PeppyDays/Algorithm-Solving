N = int(input())
P = [int(_) for _ in input().split()]
P.sort()
print(sum([p * m for p, m in zip(P, list(range(N, 0, -1)))]))
