from math import inf, isinf

V = 7
adj = {
    0: {2: 1, 1: 5, 0: 0},
    1: {0: 5, 3: 1, 6: 3, 5: 3, 1: 0},
    2: {0: 1, 3: 2, 2: 0},
    3: {2: 2, 1: 1, 4: 5, 5: 3, 3: 0},
    4: {3: 5, 4: 0},
    5: {1: 3, 3: 3, 6: 2, 5: 0},
    6: {1: 3, 5: 2, 6: 0},
}
C = [[None] * V for _ in range(V)]

for i in range(V):
    for j in range(V):
        if i is j:
            C[i][j] = 0
        else:
            C[i][j] = inf

for k in range(V):
    for i in range(V):
        for j in range(V):
            C[i][j] = min(C[i][j], C[i][k] + C[k][j])

