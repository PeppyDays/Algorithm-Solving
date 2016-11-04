#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int k = 1;

    while (n != 1)
    {
        if (((k*k + k) / 2) <= n && n <= (((k + 1) * (k + 1) + k + 1) / 2))
        {
            break;
        }

        k++;
    }

    if (n != 1)
        k = k + 1;

    if (k % 2 == 0)
    {
        //행에서 시작
        //분자 x, 분모 y
        int x = k;
        int y = 1;

        for (int i = 0; i < ((k*k + k) / 2) - n; i++)
        {
            //분자 --, 분모 ++
            x--;
            y++;
        }

        cout << x << "/" << y << endl;
    }
    else
    {
        //열에서 시작
        //분자 x, 분모 y
        int x = 1;
        int y = k;

        for (int i = 0; i < ((k*k + k) / 2) - n; i++)
        {
            //분자 ++, 분모 --
            x++;
            y--;
        }

        cout << x << "/" << y << endl;
    }

    return 0;
}
