#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    freopen("resources/input_arg.in", "r", stdin);
    freopen("resources/output.out", "w", stdout);

    srand((unsigned int)time(NULL));

    int T, N, M;
    scanf("%d %d %d", &T, &N, &M);

    // int T = 10;
    // int N = 3000;
    // int M = 3000;

    // int N = rand() % 3001;
    // int M = rand() % 3001;

    printf("%d\n", T);

    while (T--) {
        printf("%d %d\n", N, M);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                printf("%d", rand() % 2);
            }
            printf("\n");
        }
    }

    return 0;
}



