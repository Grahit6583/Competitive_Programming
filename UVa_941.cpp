#include<bits/stdc++.h>

using namespace std;

void permutations(string &s, int l, int r, vector<string> &ans)
{
    if(l == r)
    {
        ans.push_back(s);
        return;
    }

    for(int i=l; i<=r; i++)
    {
        swap(s[l],s[i]);

        permutations(s, l+1, r, ans);

        swap(s[l],s[i]);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t)
    {
        string s;
        cin>>s;
        int index;
        cin>>index;

        vector<string> ans;
        permutations(s, 0, s.size()-1, ans);

        sort(ans.begin(), ans.end());
        cout<<ans[index]<<endl;
        t--;
    }

    return 0;
}