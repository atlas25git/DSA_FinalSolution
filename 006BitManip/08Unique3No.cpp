#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //here we observe the property that a no. if repeated  3 times
    //and just one that is repeated once, the bit wose positional sum would
    //be of the form 3N+1/0, store the sum and take %3
    int cnt[64]={0};
    int n,no;
    cin>>n;
    cout<<"n: "<<n<<endl;
    for(int i=0;i<n;i++)
    {   
        cin>>no;
        int j=0;
        while(no>0)
        {
            int lb = (no&1);
            cnt[j] += lb;
            j++;
            //cout<<j<<"th step: "<<endl;
            no=no>>1;
        }

    }

    int p=1;
    int ans=0;
    for(int i=0;i<64;i++)
    {
        cnt[i] %= 3;
        ans += cnt[i]*p;
        //cout<<i<<"th step: "<<endl;
        p = p<<1;
    }

    cout<<ans<<endl;
}