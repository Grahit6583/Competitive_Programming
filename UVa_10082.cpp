#include<bits/stdc++.h>

using namespace std;

string Simulation(string s)
{
    vector<char> vec1 = {'`','1','2','3','4','5','6','7','8','9','0','-','='};
    vector<char> vec2 = {'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'};
    vector<char> vec3 = {'A','S','D','F','G','H','J','K','L',';','\''};
    vector<char> vec4 = {'Z','X','C','V','B','N','M',',','.','/'};
    vector<char> st(s.length());
    for(int i=0; i<s.length(); i++)
    {
        bool flag = true;
        if(flag)
        {   
            for(int j=0; j<vec1.size(); j++)
            {
                if(s[i] == vec1[j])
                {
                    st[i] = vec1[j-1];
                    flag = false;
                    break;
                }
            }   
        }
        if(flag)
        {
            for(int j=0; j<vec2.size(); j++)
            {
                if(s[i] == vec2[j])
                {
                    st[i] = vec2[j-1];
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            for(int j=0; j<vec3.size(); j++)
            {
                if(s[i] == vec3[j])
                {
                    st[i] = vec3[j-1];
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            for(int j=0; j<vec4.size(); j++)
            {
                if(s[i] == vec4[j])
                {
                    st[i] = vec4[j-1];
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            st[i] = ' ';
        }
    }

    return string(st.begin(), st.end());
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;

    while (getline(cin,s))
    {
        string ans;
        ans = Simulation(s);
        cout<<ans<<endl;
    }

    return 0;
}