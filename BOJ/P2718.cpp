#include <cstdio>
#include <cstring>
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

const int MaxN = 100;
int T, N;
int cache[MaxN][1 << 4];

int fillTile(int n, int s);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(cache, -1, sizeof(cache));
    getIn();
    T = nextInt();

    while (T--) {
        N = nextInt();
        printf("%d\n", fillTile(N, 15));
    }

    return 0;
}

int fillTile(int n, int s) {
    if (n == 1) {
        if (s == 0 || s == 3 || s == 6 || s == 12 || s == 15) return 1;
        else return 0;
    }

    if (s == 0)
        return fillTile(n - 1, 15);

    if (cache[n][s] != -1)
        return cache[n][s];

    int& ret = cache[n][s];
    ret = 0;

    if (s == 1) { ret += fillTile(n - 1, 14); }
    if (s == 2) { ret += fillTile(n - 1, 13); }
    if (s == 3) { ret += fillTile(n - 1, 15); ret += fillTile(n - 1, 12); }
    if (s == 4) { ret += fillTile(n - 1, 11); }
    if (s == 5) { ret += fillTile(n - 1, 10); }
    if (s == 6) { ret += fillTile(n - 1, 9); ret += fillTile(n - 1, 15); }
    if (s == 7) { ret += fillTile(n - 1, 8); ret += fillTile(n - 1, 11); ret += fillTile(n - 1, 14); }
    if (s == 8) { ret += fillTile(n - 1, 7); }
    if (s == 9) { ret += fillTile(n - 1, 6); }
    if (s == 10) { ret += fillTile(n - 1, 5); }
    if (s == 11) { ret += fillTile(n - 1, 4); ret += fillTile(n - 1, 7); }
    if (s == 12) { ret += fillTile(n - 1, 3); ret += fillTile(n - 1, 15); }
    if (s == 13) { ret += fillTile(n - 1, 2); ret += fillTile(n - 1, 13); }
    if (s == 14) { ret += fillTile(n - 1, 1); ret += fillTile(n - 1, 7); ret += fillTile(n - 1, 13); }
    if (s == 15) { ret += fillTile(n - 1, 0); ret += fillTile(n - 1, 3); ret += fillTile(n - 1, 6); ret += fillTile(n - 1, 12); ret += fillTile(n - 1, 15); }

    return ret;
}
