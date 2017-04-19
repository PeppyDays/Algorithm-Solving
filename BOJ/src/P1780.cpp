#include <stdio.h>
using namespace std;

const int MaxN = 2187;

int n;
int paper[MaxN][MaxN];
int res[3];

void solve(int x, int y, int size);
int check(int x, int y, int size);

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &paper[i][j]);

    solve(0, 0, n);

    for (int i = 0; i < 3; ++i)
        printf("%d\n", res[i]);

    return 0;
}

void solve(int x, int y, int size) {
    int pure = check(x, y, size);
    if (pure != -2) {
        // printf("x(%d) y(%d) size(%d)  pure(%d)\n", x, y, size, pure);
        res[pure + 1]++;
        return;
    }

    size /= 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            solve(x + size * dx, y + size * dy, size);
        }
    }

    return;
}

int check(int x, int y, int size) {
    int res = paper[x][y];

    for (int dx = 0; dx < size; dx++) {
        for (int dy = 0; dy < size; dy++) {
            if (res != paper[x + dx][y + dy]) {
                res = -2;
                break;
            }
        }

        if (res == -2)
            break;
    }

    return res;
}
