#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

#define MaxN 51
#define INF 1000000001
#define EXPAND_X "X+YF"
#define EXPAND_Y "FX-Y"

int N, P, L;
int length[MaxN];

void precalc();
char expand(const string& dragonCurve, int generations, int skip);

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("input.in", "r", stdin);

    precalc();
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> P >> L;

        for (int i = P; i < P + L; i++)
            cout << expand("FX", N, i - 1);
        cout << '\n';
    }

    return 0;
}

char expand(const string& dragonCurve, int generations, int skip) {
    if (generations == 0) {
        return dragonCurve[skip];
    }

    for (int i = 0; i < dragonCurve.size(); ++i)
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
            if (skip >= length[generations])
                skip -= length[generations];
            else if (dragonCurve[i] == 'X')
                return expand(EXPAND_X, generations - 1, skip);
            else
                return expand(EXPAND_Y, generations - 1, skip);
        else if (skip > 0)
            --skip;
        else
            return dragonCurve[i];

    return '#';
}

void precalc() {
    length[0] = 1;
    for (int i = 1; i < MaxN; i++) {
        length[i] = min(INF, 2 * length[i - 1] + 2);
    }
}
