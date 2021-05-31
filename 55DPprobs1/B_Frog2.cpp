//since we're given that the frog would take 2 steps,, therefore we'll approach the problem from the last
//here since k=100, th overal complexity ebing 10^5 * 100 = 10^7

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> ar,int n,int k)
{
    vector<int> dp(n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++){
       
       dp[i]=INT_MAX;
       for(int j=i-1;j>=1&&(i-j)<=k;j--)
       {
           dp[i]=min( dp[i] , abs(ar[i] -ar[j]) + dp[j] );
       }
    }
    return dp[n];
}

int main()
{
    int n,k;cin>>n>>k;
    vector<int> ar(n+1);
    for(int i=1;i<=n;i++)cin>>ar[i];
    cout<<solve(ar,n,k)<<endl;
}