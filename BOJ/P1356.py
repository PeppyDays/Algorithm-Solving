from functools import reduce

N = [int(_) for _ in input()]
flag = False

for split in range(1, len(N)):
    N1 = reduce(lambda x, y: x * y, N[:split])
    N2 = reduce(lambda x, y: x * y, N[split:])

    if N1 == N2:
        flag = True
        break

if flag:
    print('YES')
else:
    print('NO')
