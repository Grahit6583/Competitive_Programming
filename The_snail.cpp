#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float height;
    float climb, slide, fatique;
    while (cin >> height >> climb >> slide >> fatique && height)
    {
        float curr_pos = 0;
        fatique = climb * fatique / 100;
        int day = 1;

        while (curr_pos < height && curr_pos >= 0)
        {
            curr_pos += climb;
            if (climb > 0)
            {
                climb -= fatique;
            }
            if (curr_pos > height)
            {
                break;
            }
            curr_pos -= slide;
            if (curr_pos < 0)
            {
                break;
            }
            day++;
        }
        if (curr_pos < 0)
        {
            cout << "failure on day " << day << endl;
        }
        else
        {
            cout << "success on day " << day << endl;
        }
    }
    return 0;
}