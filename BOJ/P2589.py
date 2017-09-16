from queue import Queue
import sys


sys.setrecursionlimit(100000)

N, M = (int(_) for _ in input().split())
Board = []

for _ in range(N):
    Board.append([_ for _ in input()])


def bfs(start: tuple) -> int:
    global N, M, Board

    dist = [[None] * M for _ in range(N)]
    q = Queue()

    q.put(start)
    dist[start[0]][start[1]] = 0

    ret = -1

    while not q.empty():
        here = q.get()
        dist_to_here = dist[here[0]][here[1]]

        ret = max(ret, dist_to_here)

        for dr, dc in zip([-1, 0, 1, 0], [0, 1, 0, -1]):
            there = (here[0] + dr, here[1] + dc)

            if 0 <= there[0] < N and 0 <= there[1] < M \
                    and Board[there[0]][there[1]] is 'L' and dist[there[0]][there[1]] is None:
                dist[there[0]][there[1]] = dist_to_here + 1
                q.put(there)

    return ret


ret = -1

for r in range(N):
    for c in range(M):
        if Board[r][c] is 'L':
            ret = max(ret, bfs((r, c)))

print(ret)
