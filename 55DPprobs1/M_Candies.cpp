//dp(i,j) -> no of ways to distribute j candies among the first i childeren : [1,i]
//do[N,K] =  this can be given by: dp(N-1,K)//0 candies to Nth
                                // + dp(N-1,K-1)// 1 candy to Nth
                                // + dp(N-1,K-2)//2 candies to Nth
                                //.
                                //.
                                //+ dp(N-1,K-an);

                //Therefore dp(i,j) = summation_over_x(0 to Ai)dp(i-1,j-x);
                //Base Case:
                //Only one child: dp(1,j) = 1 //j<=a1 -> all candies given to one child
                //                        = 0//j>a1 -> no ways
                //space complex: O(NK)
                //Time: O(N(K^2))
                //Optimization Technique:

//***************************************************************************************************************************
                
                //state dp(i,k) = {
                //    (i-1,K),(i-1,K-1),(i-1,K-2)......,(i-1,K-ai)
                //}
                //state dp(i,k-1) = {
                //    (i-1)(K-1),(i-1)(K-1-1)..........,(i-1,K-1-ai)
                //}
                //Here given the repetitive of most of the states consecutive states could be calculated in O(1)
                //Transition time->O(Nk2)->O(Nk)
            //Final recurrence: dp(i,j+1),given we have calculated dp(i,j):
            //dp(i,j+1) = dp(i,j) + dp(i-1,j+1) - dp(i,j-ai); 

//**************************************************solution********************************************************************
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int solve(vector<int>&v,int n,int k)
{

    ll dp[n+2][k+2];
     
     for(int j=0;j<=k;j++)
        dp[1][j]=(j>v[1])?0:1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)dp[i][j]=dp[i-1][j];

            else dp[i][j] = (mod+dp[i][j-1] + dp[i-1][j] -((j-v[i]-1 >= 0)? dp[i-1][j-v[i]-1]:0))%mod;

        }
    }
    return dp[n][k];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n,k);
    return 0;
}