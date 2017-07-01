#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 10;

int N, cache[MaxN][2];
vector<int> child[MaxN];

int get(int node, bool early);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);

    int u, v;
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        child[u].push_back(v);
    }

    int answer = min(get(1, false), get(1, true));
    printf("%d", answer);

    return 0;
}

// 시작노드 번호, 시작노드의 얼리어답터 여부 -> 최소의 early adapter 수
int get(int node, bool early) {
    // leaf node 인 경우, 자신의 early 여부에 따라 return
    if (child[node].size() == 0)
        return early;
    
    if (cache[node][early] != -1)
        return cache[node][early];

    int& ret = cache[node][early];
    
    // 자신이 early adapter 인 경우, 자손들은 early adapter 여부 맘대로
    if (early) {
        ret = 1;
        for (int c = 0; c < child[node].size(); ++c)
            ret += min(get(child[node][c], false), get(child[node][c], true));
    }
    // 자신이 early adapter 가 아닌 경우, 자손들은 무조건 전부 early adapter
    else {
        ret = 0;
        for (int c = 0; c < child[node].size(); ++c)
            ret += get(child[node][c], true);
    }

    return ret;
}
