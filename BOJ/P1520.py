M, N = (int(x) for x in input().split())
B = []
C = [[-1] * N for _ in range(M)]

for r in range(M):
    B.append([int(x) for x in input().split()])


def find(r: int, c: int) -> int:
    if r >= M or c >= N or r < 0 or c < 0:
        return 0

    if r == M - 1 and c == N - 1:
        return 1

    if C[r][c] is not -1:
        return C[r][c]

    ret = 0

    for dr, dc in zip([-1, 0, 1, 0], [0, 1, 0, -1]):
        if r + dr < M and c + dc < N and r + dr >= 0 and c + dc >= 0 and B[r + dr][c + dc] < B[r][c]:
            ret += find(r + dr, c + dc)

    C[r][c] = ret

    return ret


print(find(0, 0))
