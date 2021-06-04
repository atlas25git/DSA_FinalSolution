//*********************************************DP-With-BitMasking*************************************

//given n men and women with a copatibility matrix, we got to discern no of ways unique pairing is possible
//brute force
//1st man and ith women compatible as c[1,i] = 1;
//now calculate all the pairs that could be made using 2 to N men and all women except the ith 

//dp sol
//dp(i,X): No of ways to maake valid pairs st [i-N] men are available and set of Women represented by X
//dp(1,W) -> men vl [1 to N] and W+{1.2.3,4......N}
//dp(1,w) = summation(C(1,x)==1, x-> W)dp(2,W-{x});

//Final recurrence: 
//Here the second dimension of the dp table is a set rather than an int
//dp(i,X) = summation(c[i,x]==1,x->X)dp(i+1,X-{x});
//representing the set as a boolean array
//using bitmasking to represent the set

//base case for the recurrence:
//dp(N+1,X) = 1 if no women available and so are the men none avl
//          = 0 X!=0 but no compatible men available


//****************************************CODE**********************************************************************

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod =1e9+7;

ll dp[22][(1<<22)];//0 bassed indexing it's already 1<<22 -1

int solve(vector<vector<int>>& compat, int i,int womenSubset,int N)
{   
    //all men already paired
    if(i == N+1)
    {
        if(womenSubset == 0)return 1;
        return 0;
    }
    if(dp[i][womenSubset]!=-1) return dp[i][womenSubset];

    ll ans=0;
    for(int women=0;women<N;women++)
    {
         bool available = (((1<<women)&(womenSubset))==0 ?
                                                        //she ain't available
                                                        0
                                                        :
                                                        //she avl
                                                        1);

        if(available && compat[i][women+1])
        {
            ans = (ans+solve(compat,i+1,womenSubset^(1<<women),N))%mod;
        }
    }
    return dp[i][womenSubset] = ans;
}



int main(){
    int n;
    cin>>n;
    vector<vector<int>> compat(n+1,vector<int>(n+1));
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>compat[i][j];
        }
       
    }
    cout<<solve(compat,1,((1<<(n))-1),n);
    return 0;
}