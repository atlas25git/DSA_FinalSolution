//adj slimes could be combined and their hieght sum is the cost incurred,
//we've to divise a method to do the operation with min cost  
//recurrence: dp(i,j) = min cost to combine al slime in [i,j] into 1 slime.
//dp(i,N)-> prefix of (1 to i) and suffix (i to N); i reanges from 1 to N-1
//dp(i,j) = sum(i,j) + dp(i,k) + dp(i+K+1,j) , k=[i to j-1]
//basecase dp(i,i) = 0;

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL<<60)

ll dp[3001][3001];
ll sum[3001][3001];

ll solve(vector<int>&v,int i,int j)
{
    if(i==j)return 0;
    
    if(dp[i][j]!=-1)
            return dp[i][j];
            
    ll minCost = inf;
    for(int k=i;k<j;k++)
    {
        minCost = min(minCost, sum[i][j] + solve(v,i,k) + solve(v,k+1,j));
    }
    return dp[i][j]=minCost;  
}

void preprocess(vector<int>&v,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            {
                sum[i][j] = v[j] + (( j==i ) ? 0 : sum[i][j-1]);
                //cout<<sum[i][j]<<" ";
                //cout<<"->V"<<v[j]<<" ";
            }
            //cout<<endl;
    }
}

int main(){
    int n; cin>>n;
    memset(dp,-1,sizeof dp);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    preprocess(v,n);
    cout<<solve(v,1,n);
    return 0;
}
 