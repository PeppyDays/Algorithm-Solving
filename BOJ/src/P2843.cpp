#include <cstdio>
#include <vector>
using namespace std;

#define MaxN 300001
#define MaxQ 300001

int N, Q;
int Next[MaxN];
int Parent[MaxN];
int Query[MaxQ][3];
int End[MaxN];
bool Loop[MaxN];
int Rank[MaxN];

vector<int> Answer;

void initialize();
void merge(int u, int v);
int find(int u);

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &Next[i]);

    scanf("%d", &Q);
    int q, n, m;
    for (int i = 1; i <= Q; ++i) {
        scanf("%d %d", &q, &n);
        Query[i][0] = q;
        Query[i][1] = n;
        if (q == 2) {
            Query[i][2] = Next[n];
            Next[n] = 0;
        }
    }

    initialize();

    for (int i = Q; i >= 1; --i) {
        q = Query[i][0];
        n = Query[i][1];

        if (q == 1) {
            if (Loop[find(n)])
                Answer.push_back(0);
            else
                Answer.push_back(End[find(n)]);
        }
        else if (q == 2) {
            m = Query[i][2];
            merge(n, m);
        }
    }

    for (int i = Answer.size() - 1; i >= 0; --i)
        if (Answer[i] == 0)
            printf("%s\n", "CIKLUS");
        else
            printf("%d\n", Answer[i]);

    return 0;
}

void initialize() {
    for (int start = 1; start <= N; ++start) {
        if (Parent[start] != 0)
            continue;

        int here = start;
        while (here != 0) {
            Parent[here] = start;
            End[start] = here;
            here = Next[here];

            if (here == 0 || Parent[here] == 0)
                continue;

            if (Parent[here] == start)
                Loop[start] = true;
            else if (Parent[here] != start) {
                Parent[start] = find(here);
                Rank[find(here)] += 1;
            }

            break;
        }
    }
}

int find(int u) {
    if (u == Parent[u])
        return u;

    return Parent[u] = find(Parent[u]);
}

void merge(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);

    if (uRoot == vRoot) {
        Loop[uRoot] = true;
        return;
    }

    if (Rank[uRoot] < Rank[vRoot])
        Parent[uRoot] = vRoot;
    else
        Parent[vRoot] = uRoot;

    if (Rank[uRoot] == Rank[vRoot])
        Rank[uRoot] += 1;

    Loop[uRoot] = Loop[vRoot];
    End[uRoot] = End[vRoot];
}

