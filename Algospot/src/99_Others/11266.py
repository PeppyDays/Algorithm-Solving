V, E = [int(x) for x in input().split()]
G = {}

discovered = [0] * V
is_cut_vertex = [False] * V
counter = 1


def dfs(here, is_root):
    global counter

    discovered[here] = counter
    counter += 1
    ret = discovered[here]

    child = 0
    for there in G.get(here, []):
        if not discovered[there]:
            child += 1
            subtree = dfs(there, False)
            if not is_root and subtree >= discovered[here]:
                is_cut_vertex[here] = True

            ret = min(ret, subtree)
        else:
            ret = min(ret, discovered[there])

    if is_root:
        is_cut_vertex[here] = (child >= 2)

    return ret


for item in range(E):
    i, j = [int(x)-1 for x in input().split()]
    G.setdefault(i, []).append(j)
    G.setdefault(j, []).append(i)

# for i in range(V):
#     if not discovered[i]:
#         dfs(i, True)

dfs(0, True)

cnt = sum([1 for x in is_cut_vertex if x])
vertexes = ' '.join([str(i+1) for i, x in enumerate(is_cut_vertex) if x])

print(cnt)
print(vertexes)
