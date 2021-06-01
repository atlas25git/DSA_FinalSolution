//start with thinking about possible paths to the detnation
//from just one cell behind it
//dp[i,j]: no of paths starting at i,j and ending at n,m
//if both the cells are unblocked then ->dp[i,j] = dp[i+1,j]+dp[i,j+1]
//if the cell is blocked-> dp[i,j] = 0 
//run the algorithm on sample input

#include<bits/stdc++.h>
using namespace std;

char grid[1002][1002];

int mod = 1000000007;
int solve(int n,int m){
    int dp[n+1][m+1];
    dp[n][m]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(i==n && j==m)continue;
            if(grid[i][j] == '#')
                     dp[i][j]=0;

            else dp[i][j] = (   (   (i==n)?0:dp[i+1][j] ) + (   (j==m)?0:dp[i][j+1] )   )%mod;
        }
    }
    return dp[1][1];
}

int main(){
    int n,m;
    cin>>n>>m;
    //memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
               {cin>>grid[i][j];}
    }
    
   cout<<solve(n,m);

}