#include <iostream>
#include <vector>
using namespace std;

// Class Operator Overloading
class NumBox {
public:
    int number;

    NumBox() {
        number = 0;
    }

    bool operator < (const NumBox& x) {
        return number < x.number;
    }
};

// bool operator < (const NumBox& a, const NumBox& b) {
//     return a.number < b.number;
// }

// bool operator > (const NumBox& a, const NumBox& b) {
//     return a.number > b.number;
// }

class CompareBy {
public:
    bool operator() (const NumBox& a, const NumBox& b) {
        return b.number > a.number;
    }
};

int main() {
    NumBox a, b;
    a.number = 3;
    b.number = 4;

    cout << ((a < b) ? "true" : "false") << ' ' << ((b < a) ? "true" : "false") << ' ' << endl;

    vector<NumBox> v;
    v.push_back(a);
    v.push_back(b);

    sort(v.begin(), v.end(), CompareBy());

    cout << v[0].number << endl;
    cout << v[1].number << endl;

    return 0;
}