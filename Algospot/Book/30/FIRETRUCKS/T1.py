# 문제 링크
# https://algospot.com/judge/problem/read/FIRETRUCKS


from collections import defaultdict
from queue import PriorityQueue


def dijkstra(start):
    global adj, V

    distances = [None] * (V + 1)
    q = PriorityQueue()

    distances[0] = 0
    q.put((0, start))

    while not q.empty():
        dist_to_here, here = q.get()

        if dist_to_here > distances[here]:
            continue

        for there, dist_here_to_there in adj.get(here, {}).items():
            if distances[there] is None or distances[there] > dist_to_here + dist_here_to_there:
                distances[there] = dist_to_here + dist_here_to_there
                q.put((distances[there], there))

    return distances


T = int(input())

for t in range(T):
    V, E, _, _ = [int(x) for x in input().split()]
    adj = defaultdict(dict)

    for _ in range(E):
        u, v, c = [int(x) for x in input().split()]
        adj[u][v] = c
        adj[v][u] = c

    fires = [int(x) for x in input().split()]
    stations = [int(x) for x in input().split()]

    for station in stations:
        adj[0][station] = 0

    distances = dijkstra(0)
    Answer = 0
    for fire in fires:
        Answer += distances[fire]

    print(Answer)
