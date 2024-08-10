#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string change_Quotes(string s, int &cnt)
{
    for(int i=0; i<=s.length(); i++)
    {
        if(s[i] == '"' && cnt%2 == 0)
        {
            cnt++;
            s[i] = '`';
            s.insert(i+1, "`");
        }
        else if(s[i] == '"' && cnt%2 == 1)
        {
            cnt++;
            s[i] = '\'';
            s.insert(i+1, "'");
        }
    }

    return s;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    int cnt =0;
    while (getline(cin, s))
    {
        cout<<change_Quotes(s, cnt)<<endl;
    }
    
    return 0;
}