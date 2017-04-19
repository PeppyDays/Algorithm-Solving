#include <iostream>
using namespace std;

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string dayName[7] = {"SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT"};

int main() {
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;

    int daySum = y;
    for (int i = 1; i < x; i++)
        daySum += days[i];

    cout << dayName[daySum % 7] << '\n';

    return 0;
}

