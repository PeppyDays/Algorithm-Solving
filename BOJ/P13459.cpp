#include <cstdio>
using namespace std;

char in[10000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return ret;
}



int main() {
    freopen("resources/input.in", "r", stdin);



    return 0;
}