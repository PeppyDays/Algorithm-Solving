number_of_vertexes, number_of_edges = (int(_) for _ in input().split())
adjacent_map = [[] for _ in range(number_of_vertexes)]
discovered_order = [None] * number_of_vertexes
group_id = [None] * number_of_vertexes
groups = []

discovered_counter = 0
group_counter = 0

stack = []

for _ in range(number_of_edges):
    from_vertex, to_vertex = (int(_) - 1 for _ in input().split())
    adjacent_map[from_vertex].append(to_vertex)


def find_scc(here: int) -> int:
    global adjacent_map, discovered_order, group_id
    global discovered_counter, group_counter

    ret = discovered_counter
    discovered_order[here] = discovered_counter
    discovered_counter += 1

    stack.append(here)

    for there in adjacent_map[here]:
        if discovered_order[there] is None:
            ret = min(ret, find_scc(there))
        elif discovered_order[there] < discovered_order[here] and group_id[there] is None:
            ret = min(ret, discovered_order[there])

    if ret == discovered_order[here]:
        group = []

        while True:
            member = stack.pop()
            group_id[member] = group_counter
            group.append(member)

            if here == member:
                break

        groups.append(group)
        group_counter += 1

    return ret


for here in range(number_of_vertexes):
    if discovered_order[here] is None:
        find_scc(here)

for group in groups:
    group.sort()

groups.sort()

print(group_counter)
for group in groups:
    print(' '.join([str(member + 1) for member in group]) + ' -1')
