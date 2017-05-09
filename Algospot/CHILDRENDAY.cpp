#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MaxN = 10000;

int N, M, T;
bool digits[10];

int append(int here, int edge) {
    return (10 * here + edge) % N;
}

int gifts() {
    vector<int> parent(N, -1), choice(N, -1);
    queue<int> q;
    parent[0] = 0;
    q.push(0);


}

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d", &T);

    while (T--) {
        memset(digits, 0, sizeof(digits));

        char buf[10];
        scanf("%s", buf);
        scanf("%d %d", &N, &M);

        for (int i = 0; i < 10; ++i) {
            if (buf[i] == '\0') break;
            digits[buf[i] - '0'] = true;
        }












    }


    return 0;
}
