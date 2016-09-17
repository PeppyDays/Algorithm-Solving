from collections import defaultdict
from queue import Queue


def bfs(start, distance, parent):
    global V, adj

    q = Queue()
    q.put(start)
    distance[start] = 0
    parent[start] = start

    while not q.empty():
        here = q.get()

        for there in adj.get(here, []):
            if distance[there] is None:
                distance[there] = distance[here] + 1
                parent[there] = here
                q.put(there)


def shortest_path(v, parent):
    path = [v]
    while parent[v] != v:
        v = parent[v]
        path.append(v)

    path.reverse()

    return path


V, E = int(input()), int(input())
adj = defaultdict(list)
parent = [None] * V
distance = [None] * V

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    adj[u].append(v)
    adj[v].append(u)

bfs(0, distance, parent)

print(distance)
print(parent)
print(shortest_path(5, parent))
