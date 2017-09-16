N = int(input())
Board = []
Cache = [[-1] * N for _ in range(N)]

for _ in range(N):
    Board.append([int(_) for _ in input().split()])


def find(r: int, c:int) -> int:
    global N, Board

    if r < 0 or c < 0 or r >= N or c >= N:
        return 0

    if r == N - 1 and c == N - 1:
        return 1

    if Board[r][c] is 0:
        return 0

    if Cache[r][c] is not -1:
        return Cache[r][c]

    ret = find(r + Board[r][c], c) + find(r, c + Board[r][c])
    Cache[r][c] = ret

    return ret


print(find(0, 0))
