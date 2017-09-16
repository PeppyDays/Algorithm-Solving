t = int(input())

for _ in range(t):
    m, n, k = (int(_) for _ in input().split())
    farm = [[False] * n for _ in range(m)]

    for _ in range(k):
        u, v = (int(_) for _ in input().split())
        farm[u][v] = True

    def dfs(x: int, y: int):
        if x < 0 or y < 0 or x >= m or y >= n:
            return

        if not farm[x][y]:
            return

        farm[x][y] = False

        for dx, dy in zip((-1, 0, 1, 0), (0, 1, 0, -1)):
            dfs(x + dx, y + dy)

    ret = 0

    for x in range(m):
        for y in range(n):
            if farm[x][y]:
                dfs(x, y)
                ret += 1

    print(ret)
