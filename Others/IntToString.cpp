#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 532;

    char buf[256];
    sprintf(buf, "%d", n);
    string s = string(buf);

    cout << s << endl;

    return 0;
}