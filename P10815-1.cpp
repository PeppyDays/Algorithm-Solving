#include <cstdio>
using namespace std;

char in[1 << 25];
char out[1000001];
const char* in_p = in;
char* out_p = out;

void getIn() {
    in_p = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while ((*in_p < '0' || *in_p > '9') && *in_p != '-') ++in_p;
    if (*in_p == '-') { sign = false; in_p++; };
    while (*in_p >= '0' && *in_p <= '9') ret = 10 * ret + *in_p++ - '0';

    return sign ? ret : -ret;
}

int N, M;
bool Card[20000001];

int main() {
    freopen("resources/input.in", "r", stdin);
    getIn();
    N = nextInt();
    for (int i = 0; i < N; ++i) {
        Card[nextInt() + 10000000] = true;
    }

    M = nextInt();
    for (int i = 0; i < M; ++i) {
        *out_p++ = Card[nextInt() + 10000000] ? '1' : '0';
        *out_p++ = ' ';
    }

    puts(out);

    return 0;
}
