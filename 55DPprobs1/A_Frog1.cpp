//since we're given that the frog would take 2 steps,, therefore we'll approach the problem from the last
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> ar,int n)
{
    vector<int> dp(n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int op1 = abs(ar[i]-ar[i-1])+dp[i-1];
        int op2 = (i==2)?INT_MAX:abs(ar[i]-ar[i-2]) + dp[i-2];
        //2 being the one of 0 indexed scale
        //therefore 0->-1
        dp[i]=min(op1,op2);
    }
    return dp[n];
}
int main()
{
    int n;cin>>n;
    vector<int> ar(n+1);
    for(int i=1;i<=n;i++)cin>>ar[i];
    cout<<solve(ar,n)<<endl;
}