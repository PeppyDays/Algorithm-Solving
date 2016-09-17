INF = 9999999999

V, E = [int(x) for x in input().split()]
D = [(i, int(x)) for i, x in enumerate(input().split())]
D.sort(key=lambda x: x[1])
C = [[INF] * V for _ in range(V)]
B = [[INF] * V for _ in range(V)]

for _ in range(E):
    u, v, c = [int(x) for x in input().split()]
    C[u-1][v-1] = c
    C[v-1][u-1] = c
    B[u-1][v-1] = c
    B[v-1][u-1] = c

for i in range(V):
    C[i][i] = 0
    B[i][i] = 0

for k in range(V):
    w = D[k][0]
    dw = D[k][1]

    for u in range(V):
        if C[u][w] is INF:
            continue
        for v in range(V):
            if C[w][v] is INF:
                continue

            C[u][v] = min(C[u][v], C[u][w] + C[w][v])
            B[u][v] = min(B[u][v], C[u][w] + dw + C[w][v])

T = int(input())

for t in range(T):
    start, end = [int(x)-1 for x in input().split()]
    print(B[start][end])
