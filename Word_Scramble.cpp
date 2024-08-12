#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;

    while (getline(cin,s))
    {
        istringstream iss(s);
        string word;

        while (iss>>word)
        {
            reverse(word.begin(), word.end());
            cout<<word<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}