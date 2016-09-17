INF = 9999999999
C = int(input())

for c in range(C):
    V, M, N = [int(x) for x in input().split()]
    adj = [[INF] * V for _ in range(V)]
    new_edges = []

    for _ in range(M):
        u, v, c = [int(x) for x in input().split()]
        adj[u][v] = c
        adj[v][u] = c

    for _ in range(N):
        new_edges.append([int(x) for x in input().split()])

    for i in range(V):
        adj[i][i] = 0

    for k in range(V):
        for u in range(V):
            if adj[u][k] is INF:
                continue
            for v in range(V):
                if adj[k][v] is INF:
                    continue
                adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v])

    result = []

    for edge in new_edges:
        s = edge[0]
        e = edge[1]
        c = edge[2]

        if adj[s][e] <= c:
            result.append(False)
            continue

        adj[s][e] = c
        adj[e][s] = c
        updated = False

        for k in edge[0:2]:
            for u in range(V):
                if adj[u][k] is INF:
                    continue
                for v in range(V):
                    if adj[k][v] is INF:
                        continue

                    if adj[u][k] + adj[k][v] < adj[u][v]:
                        updated = True
                        adj[u][v] = adj[u][k] + adj[k][v]

        result.append(updated)

    print(sum([1 for r in result if not r]))
