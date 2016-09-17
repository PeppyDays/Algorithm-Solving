from collections import defaultdict
from queue import Queue


def bfs(start):
    global adj, V

    order = []
    q = Queue()
    q.put(start)
    discovered = [False] * V
    discovered[start] = True

    while not q.empty():
        here = q.get()
        order.append(here)

        for there in adj.get(here, []):
            if not discovered[there]:
                discovered[there] = True
                q.put(there)

    return order


V, E = int(input()), int(input())
adj = defaultdict(list)

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    adj[u].append(v)
    adj[v].append(u)

print(bfs(0))
