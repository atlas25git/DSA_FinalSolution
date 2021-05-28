#include<bits/stdc++.h>
using namespace std;


int minCoinsBUP(int n,int coins[],int T,int dp[])
{
   
   for(int n=1;n<=N;i++)[
       dp[i]=INT_MAX;
       for(int i=0;i<T;i++)
       {
           if(n-coins[i]>0){
               int subprob = dp[n-coins[i]];
               dp[i] = min(dp[i],subprob+1);
           }
       }
   ]
   return dp[N];
}


int main(){
    int N=15;
    int copins[]={1,7,10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);
    cout<<minCoinsBUP(n,coins,T,dp);
    return 0;

}