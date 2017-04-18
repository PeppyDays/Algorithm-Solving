#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

class student {
public:
    string name;
    int s1, s2, s3;

    void setAttr(string _name, int _s1, int _s2, int _s3) {
        name = _name; s1 = _s1; s2 = _s2; s3 = _s3;
    }
};

class compareBy {
public:
    bool operator() (student st1, student st2) {
        if (st1.s1 == st2.s1)
            if (st1.s2 == st2.s2)
                if (st1.s3 == st2.s3)
                    return st1.name < st2.name;
                else
                    return st1.s3 > st2.s3;
            else
                return st1.s2 < st2.s2;
        else
            return st1.s1 > st2.s1;
    }
} compareByScore;

int n;
student students[MaxN];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    string _name;
    int _s1, _s2, _s3;
    for (int i = 0; i < n; ++i) {
        cin >> _name >> _s1 >> _s2 >> _s3;
        students[i].setAttr(_name, _s1, _s2, _s3);
    }

    sort(students, students + n, compareByScore);

    for (int i = 0; i < n; ++i)
        printf("%s\n", students[i].name.c_str());

    return 0;
}

