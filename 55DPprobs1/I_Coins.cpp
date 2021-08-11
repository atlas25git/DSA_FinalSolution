//coins are biased
//p of getting more heads than from tails
// for the given test case
//fav outcomes would be(more H than T)-> 
//1. {H,H,H} -> 0.3 * 0.6 *0.8
//2. {H,T,H} -> 0.3*0.4*0.8
//similarly for {H,,H,T} & {T,H,H}
//We've to return the summation of all these probabilities
//we need atleast N+1/2 heads out of given N coins
//dp(i,x): on tossing first i coins the prob of getting >=x heads
//dp(N,((N+1)/2))
//therefore for any dp(i,x) = {Coin Faired H} pi*dp(i-1,x-1) + {Coin Faire Tails} (1-pi)*dp(i-1,x);
//divising base cases:
//0 coins dp(0,x) = 1 when x=0, else 0

#include<bits/stdc++.h>
using namespace std;

double dp[3001][3001];
double solve(vector<double>& ar,int i,int x)
{
     if(x==0)return 1;//By tossing 0 coins we've a 1 probability of getting 0 heads.
     if(i==0)return 0;
     if(dp[i][x]>-0.9)return dp[i][x];
     return dp[i][x] = ar[i]*solve(ar,i-1,x-1) + (1-ar[i])*solve(ar,i-1,x);
}


int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<double> ar(n+1);

    for(int i=1;i<n+1;i++)cin>>ar[i];

    cout<<fixed<<setprecision(10)<<solve(ar,n,(n+1)/2);
}
