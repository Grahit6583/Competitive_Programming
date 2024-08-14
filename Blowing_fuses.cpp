#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int no_devices,operations,capacity;
    int Sequence = 0;
    while (cin>>no_devices>>operations>>capacity && no_devices)
    {
        Sequence++;
        vector<pair<int,bool>> power_consume(no_devices+1);
        for(int i=1; i<=no_devices; i++)
        {
            int amperes;
            cin>>amperes;
            pair<int,bool> p = make_pair(amperes, false);
            power_consume[i] = p;
        }

        int power_consumption = 0;
        int max_consumption = INT_MIN;
        int fuse_blown = false;

        for(int i=1; i<=operations; i++)
        {
            int toggling_device;
            cin>>toggling_device;
            if(power_consume[toggling_device].second == false && fuse_blown == false)
            {
                power_consume[toggling_device].second = true;
                power_consumption = power_consumption + power_consume[toggling_device].first;
                max_consumption = max(max_consumption, power_consumption);
                if(power_consumption > capacity)
                {
                    fuse_blown = true;
                }
            }
            else if(fuse_blown == false)
            {
                power_consume[toggling_device].second = false;
                power_consumption = power_consumption - power_consume[toggling_device].first;
                max_consumption = max(max_consumption, power_consumption);
            }
        }
        
        if(fuse_blown)
        {
            cout<<"Sequence "<<Sequence<<endl;
            cout<<"Fuse was blown.\n\n";
        }
        else
        {
            cout<<"Sequence "<<Sequence<<endl;
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<max_consumption<<" amperes.\n\n";
        }
    }
    
    return 0;
}