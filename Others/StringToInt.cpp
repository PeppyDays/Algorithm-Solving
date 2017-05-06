#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "81209";
    string b = "12.5";

    int n = atoi(a.c_str());
    double m = atof(b.c_str());

    cout << n << endl;
    cout << m << endl;

    return 0;
}
