#include <cstdio>
using namespace std;

int N, r, c;
int find (int r, int c, int size);

int main() {
    scanf("%d %d %d", &N, &r, &c);
    N = 1 << N;

    printf("%d\n", find(r, c, N) - 1);

    return 0;
}

int find (int r, int c, int size) {
    if (size == 1)
        return 1;

    size /= 2;
    int quadrant = (r >= size) * 2 + (c >= size);
    r = (r < size) ? r : r - size;
    c = (c < size) ? c : c - size;

    return size * size * quadrant + find(r, c, size);
}
