import sys

sys.setrecursionlimit(100000)

N, M = [int(_) for _ in input().split()]
Board = []
Cache = [[[None, None] for _ in range(M)] for _ in range(N)]
visited = [[False] * M for _ in range(N)]

for _ in range(N):
    Board.append([int(_) for _ in input()])


def find(r: int, c: int, breaker: int) -> int:
    global N, M, Board, visited

    if r == N - 1 and c == M - 1:
        return 1

    if r < 0 or c < 0 or r >= N or c >= M:
        return -1

    if breaker is 0 and Board[r][c] is 1:
        return -1

    if visited[r][c]:
        return -1

    if Cache[r][c][breaker] is not None:
        return Cache[r][c][breaker]

    visited[r][c] = True

    if Board[r][c] is 1:
        breaker = 0

    ret = float('inf')

    for dr, dc in zip([-1, 0, 1, 0], [0, 1, 0, -1]):
        sub_ret = find(r + dr, c + dc, breaker)

        if sub_ret is -1:
            continue

        ret = min(ret, sub_ret + 1)

    visited[r][c] = False

    if ret == float('inf'):
        ret = -1

    Cache[r][c][breaker] = ret
    return ret


print(find(0, 0, 1))
