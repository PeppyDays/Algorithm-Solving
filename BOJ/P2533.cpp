#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char in[2000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';
    return ret;
}

const int MaxN = 1000001;

int N, cache[MaxN][2];
bool check[MaxN];
vector<int> child[MaxN];

int get(int node, bool early);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(cache, -1, sizeof(cache));
    memset(check, 0, sizeof(check));
    getIn();

    N = nextInt();

    int u, v;
    for (int i = 0; i < N - 1; ++i) {
        u = nextInt(); v = nextInt();
        child[u].push_back(v);
        child[v].push_back(u);
    }

    int answer = min(get(1, false), get(1, true));
    printf("%d", answer);

    return 0;
}

// 시작노드 번호, 시작노드의 얼리어답터 여부 -> 최소의 early adapter 수
int get(int node, bool early) {
    check[node] = true;

    // leaf node 인 경우
    if (child[node].size() == 0)
        return early;

    if (cache[node][early] != -1)
        return cache[node][early];

    int& ret = cache[node][early];

    // 자신이 early adapter 인 경우, 자손들은 early adapter 가 아니다.
    if (early) {
        ret = 1;
        for (int c = 0; c < child[node].size(); ++c)
            if (!check[child[node][c]])
                ret += min(get(child[node][c], false), get(child[node][c], true));
    }
    else {
        ret = 0;
        for (int c = 0; c < child[node].size(); ++c)
            if (!check[child[node][c]])
                ret += get(child[node][c], true);
    }

    check[node] = false;
    return ret;
}