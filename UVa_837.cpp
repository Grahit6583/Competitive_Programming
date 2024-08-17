#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<float,float>,float>> light_projected(int n, vector<vector<float>> &films)
{
    for(int i=0; i<n; i++)
    {
        if(films[i][0] > films[i][2])
        {
            swap(films[i][0],films[i][2]);
            swap(films[i][1],films[i][3]);
        }
    }
    vector<float> coordinates;
    for(int i=0; i<n; i++)
    {
        coordinates.push_back(films[i][0]);
    }

    for(int i=0; i<n; i++)
    {
        coordinates.push_back(films[i][2]);
    }

    vector<pair<pair<float,float>,float>> ans(coordinates.size());

    for(int i=1; i<coordinates.size(); i++)
    {
        float t = 1.0;
        for(int j=0; j<n; j++)
        {
            if(films[j][0] < coordinates[i] && coordinates[i] <= films[j][2])
            {
                t *= films[j][4];
            }
        }
        ans[i-1].first.first = coordinates[i-1];
        ans[i-1].first.second = coordinates[i];
        ans[i-1].second = t;
    }
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<vector<float>> films;

        for(int i=0; i<n; i++)
        {
            vector<float> temp;
            for(int j=0; j<5; j++)
            {
                float t;
                cin>>t;
                temp.push_back(t);
            }
            films.push_back(temp);
        }

        vector<pair<pair<float,float>,float>>ans = light_projected(n, films);
        cout<<(ans.size()-1)+2<<endl;
        cout<<"-inf "<<films[0][0]<<" 1.000"<<endl;
        for(int i=0; i<ans.size()-1; i++)
        {
            float x = ans[i].first.first;
            float y = ans[i].first.second;
            float z = ans[i].second;

            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        cout<<films[n-1][2]<<" +inf 1.000"<<endl;
        t--;
    }
    return 0;
}