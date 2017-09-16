#include <cstdio>
#include <algorithm>
#define MAX_SIZE 200000
 
char in[20000000];
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

int pos[MAX_SIZE];
 
int main() {
    getIn();
    int n, c;
    // scanf("%d %d", &n, &c);
    n = nextInt();
    c = nextInt();
 
    for(int i = 0; i < n; i++)
        // scanf("%d", pos + i);
        pos[i] = nextInt();
 
    std::sort(pos, pos + n);
 
    int left = 1, right = pos[n - 1] - pos[0];
    int ret;
 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cnt = 1;
        int start = pos[0];

        for (int i = 1; i < n; i++) {
            if (pos[i] - start >= mid) {
                cnt++;
                start = pos[i];
            }
        }
 
        if (cnt >= c) {
            ret = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
 
    printf("%d\n", ret);
 
    return 0;
}
