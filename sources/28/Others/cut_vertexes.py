from collections import defaultdict


def dfs(here, is_root):
    global counter, is_discovered, is_cut_vertex, graph

    is_discovered[here] = counter
    counter += 1
    child_cnt = 0
    ret = is_discovered[here]

    for there in graph.get(here, []):
        if not is_discovered[there]:
            child_cnt += 1
            ret_sub = dfs(there, False)

            if not is_root and ret_sub >= is_discovered[here]:
                is_cut_vertex[here] = True

            ret = min(ret, ret_sub)
        else:
            ret = min(ret, is_discovered[there])

    if is_root:
        is_cut_vertex[here] = (child_cnt >= 2)

    return ret


N, E = [int(x) for x in input().split()]
graph = defaultdict(set)

counter = 1
is_discovered = [None] * N
is_cut_vertex = [False] * N

for _ in range(E):
    u, v = [int(x) - 1 for x in input().split()]
    graph[u].add(v)
    graph[v].add(u)

for here in range(N):
    if not is_discovered[here]:
        dfs(here, True)

print(sum([1 for x in is_cut_vertex if x]))
print(' '.join([str(i + 1) for i, x in enumerate(is_cut_vertex) if x]))
