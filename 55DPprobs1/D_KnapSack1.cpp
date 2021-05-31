#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct item{
    ll wt;
    ll val;
};

ll solve(vector<item> ar,ll n,ll W)
{
    ll dp[n+1][W+1];
    
    for(ll w=0;w<=W;w++)dp[1][w]=0;

    //for just one item any value than the weight of this item would be zero 
    dp[1][ar[1].wt] = ar[1].val;
    //dp[i][j] denotes max capacity that we can incur with first i items and
    //knapsack capacity j
    
    for(ll i=2;i<=n;i++)
    {
        for(ll w=0;w<=W;w++)
        {
            dp[i][w]=dp[i-1][w];
            if(ar[i].wt>w)continue;
            dp[i][w]=max(dp[i][w], ar[i].val + dp[i-1][w - ar[i].wt]);
        }
    }
    //max would be in the i,x where x goes from 0 to W
    //here [] notation marks the array as a single one not the 2d 
    return *max_element(dp[n],dp[n]+W+1);
}



int main(){
    ll n,w;
    cin>>n>>w;
    vector<item> ar(n+1);
    for(ll i=1;i<=n;i++){
        cin>>ar[i].wt>>ar[i].val;
    }
    cout<<solve(ar,n,w);
}

