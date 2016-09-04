from collections import defaultdict

N, E = [int(x) for x in input().split()]
graph = defaultdict(list)

counter = 1
is_discovered = [None] * N
is_cut_vertex = [False] * N


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

            if not is_root and ret <= ret_sub:
                is_cut_vertex[here] = True

            ret = min(ret, ret_sub)
        else:
            ret = min(ret, is_discovered[there])

    if is_root:
        is_cut_vertex[here] = (child_cnt >= 2)

    return ret


for _ in range(E):
    i, j = [int(x) for x in input().split()]
    graph[i].append(j)

dfs(0, True)

print(is_cut_vertex)


