# 문제 링크
# https://algospot.com/judge/problem/read/NTHLON


from collections import defaultdict
from queue import PriorityQueue


def dijkstra(start):
    global adj, N

    distances = [None] * (2 * (N + 1))
    q = PriorityQueue()

    distances[start] = 0
    q.put((0, start))

    while not q.empty():
        dist_to_here, here = q.get()

        for there, dist_here_to_there in adj.get(here, {}).items():
            if distances[there] is None or distances[there] > dist_to_here + dist_here_to_there:
                distances[there] = dist_to_here + dist_here_to_there
                q.put((distances[there], there))

    return distances


T = int(input())

for t in range(T):
    deltas = []
    times = []

    for _ in range(int(input())):
        ta, tb = [int(x) for x in input().split()]
        deltas.append(ta - tb)
        times.append(ta)

    N = max([abs(delta) for delta in deltas])
    adj = defaultdict(dict)

    for n in range(-N, N + 1):
        adj_from_index = n + N

        for time, delta in zip(times, deltas):
            next_node = n + delta
            adj_to_index = next_node + N

            if next_node not in range(-N, N+1):
                continue

            adj[adj_from_index][adj_to_index] = time

    adj[2 * N + 1] = adj[N]
    del adj[N]

    distances = dijkstra(2 * N + 1)

    if distances[N] is None:
        print('IMPOSSIBLE')
    else:
        print(distances[N])
