from collections import defaultdict


def get_euler_circuit(here):
    global graph, trail

    while graph.get(here, []):
        there = graph[here].pop()
        get_euler_circuit(there)

    trail.append(here)


N, E = int(input()), int(input())
graph = defaultdict(list)
trail = []

for _ in range(E):
    u, v = [int(x) for x in input().split()]
    graph[u].append(v)

get_euler_circuit(0)
trail.reverse()
print(trail)
