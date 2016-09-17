from queue import PriorityQueue
from collections import defaultdict


V, E = int(input()), int(input())
adj = defaultdict(dict)

for _ in range(E):
    u, v, c = [int(x) for x in input().split()]
    adj[u][v] = c


def dijkstra(src):
    dist = [float('inf')] * V
    dist[src] = 0
    q = PriorityQueue()
    q.put((0, src))

    while not q.empty():
        cost_to_here, here = q.get()
        if dist[here] < cost_to_here:
            continue

        for there, cost_here_to_there in adj[here].items():
            cost_to_there = cost_to_here + cost_here_to_there
            if dist[there] > cost_to_there:
                dist[there] = cost_to_there
                q.put((cost_to_there, there))

    return dist


print(dijkstra(0))
