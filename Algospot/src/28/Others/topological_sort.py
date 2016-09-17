from collections import defaultdict


def dfs(here):
    global graph, visited, trail

    visited[here] = True

    for there in graph.get(here, []):
        if not visited[there]:
            dfs(there)

    trail.append(here)


N, E = int(input()), int(input())
graph = defaultdict(list)
for _ in range(E):
    u, v = [int(x) for x in input().split()]
    graph[u].append(v)

visited = [False] * N
trail = []


for i in range(N):
    if not visited[i]:
        dfs(i)

trail.reverse()
print(trail)

