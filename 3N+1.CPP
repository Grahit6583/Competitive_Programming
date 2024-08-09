#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max_cycle_length(int i, int j)
{
    int x, count = 1, max = 0;

    if (i > j)
    {
        swap(i, j);
    }

    while (i <= j)
    {
        x = i;
        while (x != 1)
        {
            if (x % 2 == 0)
            {
                x = x / 2;
            }
            else
            {
                x = (3 * x) + 1;
            }
            count++;
            if (x == 1)
            {
                break;
            }
        }
        if (count > max)
        {
            max = count;
        }
        count = 1;
        i++;
    }
    return max;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;

    while (cin >> i >> j)
    {
        cout << i << " " << j << " " << max_cycle_length(i, j) << endl;
    }

    return 0;
}