# 문제 링크
# https://www.acmicpc.net/problem/11400

from collections import defaultdict


def dfs(here, parent):
    global counter, graph, is_discovered, is_discovered, cut_roads

    is_discovered[here] = counter
    counter += 1
    ret = is_discovered[here]

    for there in graph.get(here, []):
        if there == parent:
            continue

        if not is_discovered[there]:
            sub_ret = dfs(there, here)

            if sub_ret > is_discovered[here]:
                cut_roads.append((min(here, there), max(here, there)))

            ret = min(ret, sub_ret)
        else:
            ret = min(ret, is_discovered[there])

    return ret


N, E = [int(x) for x in input().split()]
graph = defaultdict(list)

counter = 1
is_discovered = [None] * N
cut_roads = []

for _ in range(E):
    u, v = [int(x) - 1 for x in input().split()]
    graph[u].append(v)
    graph[v].append(u)

dfs(0, -1)

cut_roads.sort()

print(len(cut_roads))
for road in cut_roads:
    print(road[0] + 1, road[1] + 1)
