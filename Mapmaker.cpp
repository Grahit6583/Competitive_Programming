#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Array
{
public:
    string name;
    int base_add;
    int bytes;
    int dimen;
    vector<int> bound;
    Array(string name, int ba, int by, int di)
    {
        this->name = name;
        base_add = ba;
        bytes = by;
        dimen = di;
        for (int i = 0; i < 2 * di; i++)
        {
            int t;
            cin >> t;
            bound.push_back(t);
        }
    }
};

void arr_manipulation(string s, vector<int> &temp, Array *&List)
{
    vector<int> cofficients(List->dimen);
    vector<int> lower_bound(List->dimen);

    cofficients[List->dimen - 1] = List->bytes;
    int k = List->dimen - 2;
    lower_bound[0] = List->bound[0];

    for (int j = List->bound.size() - 1; j >= 2; j = j - 2)
    {
        lower_bound[j / 2] = List->bound[j - 1];
        cofficients[k] = cofficients[k + 1] * ((List->bound[j] - List->bound[j - 1]) + 1);
        k--;
    }

    int ans = List->base_add;
    for (int j = 0; j < cofficients.size(); j++)
    {
        ans = ans + cofficients[j] * (temp[j] - lower_bound[j]);
    }

    cout << List->name << "[" << temp[0];
    for (int j = 1; j < temp.size(); j++)
    {
        cout << ", " << temp[j];
    }
    cout << "] = " << ans;
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int arr = 0, queries = 0;
    cin >> arr >> queries;
    vector<Array *> List(arr);
    for (int i = 0; i < arr; i++)
    {
        string name;
        int base_add;
        int bytes;
        int dimen;
        cin >> name >> base_add >> bytes >> dimen;
        List[i] = new Array(name, base_add, bytes, dimen);
    }
    while (queries > 0)
    {
        string s;
        cin >> s;
        vector<int> temp;
        for (int i = 0; i < List.size(); i++)
        {
            if (List[i]->name == s)
            {
                for (int j = 0; j < List[i]->dimen; j++)
                {
                    int t;
                    cin >> t;
                    temp.push_back(t);
                }
                arr_manipulation(s, temp, List[i]);
                cout << endl;
            }
        }
        queries--;
    }
    return 0;
}