#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int N;
map<int, int> coords;

bool isDominated(int x, int y);
void removeDominated(int x, int y);
int registered(int x, int y);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
//    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    int C;
    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);

        coords.clear();
        int x, y, ret = 0;

        while (N--) {
            scanf("%d %d", &x, &y);
            ret += registered(x, y);
        }

        printf("%d\n", ret);
    }

    return 0;
}

bool isDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);

    if (it == coords.end())
        return false;

    return y < (it -> second);
}

void removeDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);

    if (it == coords.begin())
        return;

    --it;

    while (true) {
        if ((it -> second) > y)
            break;

        if (it == coords.begin()) {
            coords.erase(it);
            break;
        }
        else {
            map<int, int>::iterator jt = it;
            --jt;
            coords.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if (isDominated(x, y))
        return int(coords.size());

    removeDominated(x, y);
    coords[x] = y;
    return int(coords.size());
}
