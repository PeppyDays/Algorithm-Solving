#include <iostream>
#include <cstring>
#include <queue>
#include <limits>
using namespace std;

#define MaxN 501
const int INF = numeric_limits<int>::max();

int N, K;
int S[MaxN];

int CacheLen[MaxN];
int CacheCnt[MaxN];
vector<int> kthLis;

int lis(int start);
int cnt(int start);
void reconstruct(int start, int skip);

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("input.in", "r", stdin);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        S[0] = -1;
        for (int i = 1; i <= N; ++i)
            cin >> S[i];

        memset(CacheLen, -1, sizeof(int) * (N + 1));
        memset(CacheCnt, -1, sizeof(int) * (N + 1));
        kthLis.clear();

        cout << lis(0) - 1 << '\n';
        cnt(0);
        reconstruct(0, K - 1);
        for (int item : kthLis)
            cout << item << ' ';
        cout << '\n';
    }

    return 0;
}

void reconstruct(int start, int skip) {
    if (start != 0) kthLis.push_back(S[start]);

    priority_queue<pair<int, int>> followers;
    for (int next = start + 1; next <= N; ++next) {
        if (S[start] < S[next] && lis(start) == lis(next) + 1)
            followers.push(make_pair(-S[next], next));
    }

    while (!followers.empty()) {
        int index = followers.top().second;
        followers.pop();
        int count = cnt(index);
        if (count <= skip)
            skip -= count;
        else {
            reconstruct(index, skip);
            break;
        }
    }

    return;
}

int cnt(int start) {
    if (lis(start) == 1) return 1;

    int& ret = CacheCnt[start];
    if (ret != -1) return ret;

    ret = 0;
    for (int next = start + 1; next <= N; ++next) {
        if (S[start] < S[next] && lis(start) == lis(next) + 1)
            ret = min<long long>(INF, (long long)ret + cnt(next));
    }

    return ret;
}

int lis(int start) {
    int& ret = CacheLen[start];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = start + 1; next <= N; ++next) {
        if (S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    }

    return ret;
}
