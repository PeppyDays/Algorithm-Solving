#include <cstdio>
using namespace std;

int lower_bound(int* array, int s, int e, int value) {
    int m;

    while (s < e) {
        m = s + (e - s) / 2;
        if (array[m] < value) s = m + 1;
        else if (array[m] > value) e = m - 1;
        else {
            while (--m && array[m] == value) {};
            return m + 1;
        }
    }

    return s;
}

int main() {



    return 0;
}
