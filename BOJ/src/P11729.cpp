#include <stdio.h>
using namespace std;

void hanoi(int from, int to, int size);
char buf[0x400000];
int index = 0;

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", (1 << N) - 1);
    hanoi(1, 3, N);
    fwrite(buf, sizeof(char), index, stdout);

    return 0;
}

void hanoi(int from, int to, int size) {
    if (size == 1) {
        // printf("%d %d\n", from, to);
        buf[index++] = 48 + from;
        buf[index++] = ' ';
        buf[index++] = 48 + to;
        buf[index++] = '\n';
        return;
    }

    int over = 6 - from - to;
    hanoi(from, over, size - 1);
    hanoi(from, to, 1);
    hanoi(over, to, size - 1);
    return;
}
