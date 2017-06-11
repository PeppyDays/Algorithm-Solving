#include <cstdio>
using namespace std;

char buf;

int nextInt() {
    int ret = 0;
    while (buf < '0' || buf > '9') buf = getchar();
    while (buf >= '0' && buf <= '9') {ret = 10 * ret + buf - '0'; buf = getchar();}
    return ret;
}

int nextOp() {
    int ret; char op[2];
    while (buf < 'a' || buf > 'z') buf = getchar();
    op[0] = buf;
    op[1] = getchar();

    if (op[0] == 'a' && op[1] == 'd') ret = 0;
    else if (op[0] == 'r') ret = 1;
    else if (op[0] == 'c') ret = 2;
    else if (op[0] == 't') ret = 3;
    else if (op[0] == 'a') ret = 4;
    else ret = 5;

    while (buf >= 'a' && buf <= 'z') buf = getchar();

    return ret;
}

const inline void add(int& n, int idx) {
    n |= (1 << idx);
}

const inline void remove(int& n, int idx) {
    n &= ~(1 << idx);
}

const inline bool check(int& n, int idx) {
    return (n & (1 << idx)) >= 1;
}

const inline void toggle(int& n, int idx) {
    n ^= (1 << idx);
}

const inline void all(int& n) {
    n = (1 << 21) - 1;
}

const inline void empty(int& n) {
    n = 0;
}

int main() {
    buf = getchar();

    int T, n = 0, idx, op;
    T = nextInt();

    while (T--) {
        op = nextOp();

        if (op != 4 && op != 5)
            idx = nextInt();

        if (op == 1)
            remove(n, idx);
        else if (op == 2)
            printf("%d\n", check(n, idx));
        else if (op == 3)
            toggle(n, idx);
        else if (op == 5)
            empty(n);
        else if (op == 0)
            add(n, idx);
        else
            all(n);
    }

    return 0;
}