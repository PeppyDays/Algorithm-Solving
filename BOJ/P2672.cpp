#include <cstdio>
#include <algorithm>
using namespace std;

class Rect {
public:
    double xs, xe, ys, ye;

    Rect() {};
    Rect(double _xs, double _xe, double _ys, double _ye) {
        xs = _xs; xe = _xe; ys = _ys; ye = _ye;
    }
};

bool comp(const Rect& u, const Rect& v) {
    if (u.xs == v.xs)
        return v.ys > u.ys;
    else
        return v.xs > u.xs;
}

const int MaxN = 30;

int N;
Rect R[MaxN];
double X[2 * MaxN];
double Y[2 * MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d", &N);

    double a, b, c, d;
    for (int i = 0; i < N; ++i) {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        R[i] = Rect(a, a + c, b, b + d);
        X[2 * i] = a; X[2 * i + 1] = a + c;
        Y[2 * i] = b; Y[2 * i + 1] = b + d;
    }

    sort(X, X + 2 * N);
    sort(Y, Y + 2 * N);
    sort(R, R + N, comp);

    double area = 0;
    double xs, xe, ys, ye;

    for (int i = 1; i < 2 * N; ++i) {
        if (X[i] == X[i - 1])
            continue;

        xs = X[i - 1]; xe = X[i];

        for (int j = 1; j < 2 * N; ++j) {
            if (Y[j] == Y[j - 1])
                continue;

            ys = Y[j - 1]; ye = Y[j];

            for (int k = 0; k < N; ++k) {
                if (xe < R[k].xs)
                    break;

                if (xs >= R[k].xs && xe <= R[k].xe && ys >= R[k].ys && ye <= R[k].ye) {
                    area += (xe - xs) * (ye - ys);
                    break;
                }
            }
        }
    }

    if ((long long)(area) == area)
        printf("%lld\n", (long long)(area));
    else
        printf("%.2lf\n", area);

    return 0;
}
