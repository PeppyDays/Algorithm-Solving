#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("resources/input.in", "r", stdin);

    char in[100004];
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\0';

    int num[10] = {0}, idx = 0;
    while (in[idx] <= '9' && in[idx] >= '0') {
        num[in[idx] - '0'] += 1;
        idx += 1;
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum += (num[i] * i);

    if (num[0] == 0 || sum % 3 != 0)
        printf("%d", -1);
    else {
        for (int i = 9; i >= 0; --i) {
            while (num[i] > 0) {
                printf("%d", i);
                num[i]--;
            }
        }
    }

    return 0;
}