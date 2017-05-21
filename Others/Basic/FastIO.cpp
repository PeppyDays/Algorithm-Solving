#include <cstdio>
using namespace std;

char in[1 << 20];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while ((*o < '0' || *o > '9') && *o != '-') ++o;
    if (*o == '-') { sign = false; o++; };
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return sign ? ret : -ret;
}

int main() {
    getIn();

    int T = nextInt();

    return 0;
}