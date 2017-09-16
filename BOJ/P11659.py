class Fenwick:
    def __init__(self, n):
        self.tree = [0] * n

    def query(self, idx):
        ret = 0
        while idx > 0:
            ret += self.tree[idx];
            idx &= (idx - 1);

        return ret

    def update(self, idx, delta):
        while idx < len(self.tree):
            self.tree[idx] += delta
            idx += (idx & -idx)


n, m = (int(x) for x in input().split())
fenwick = Fenwick(n + 1)

for idx, delta in enumerate([int(x) for x in input().split()]):
    fenwick.update(idx + 1, delta)

for _ in range(m):
    s_idx, e_idx = (int(x) for x in input().split())
    print(fenwick.query(e_idx) - fenwick.query(s_idx - 1))
