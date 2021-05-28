#include<bits/stdc++.h>
using namespace std;

int minSteps(int n ,int dp[])
{
    if(n==1)return 0;
    int op1,op2,op3;

    if(dp[n]!=0)return dp[n];

    if(n%3){
        op1=minSteps(n/3,dp)+1;
    }
    if(n%2){
        op2=minSteps(n/2,dp)+1;
    }
    op3 = minSteps(n-1,dp)+1;
    int ans = min(min(op1,op2),op3);
    return dp[n] = ans;
}

int minStepsBU(int n){
    int dp[100]={0};
    dp[1]=0;

    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3 = INT_MAX;
        if(n%3==0)op1=dp[i/3];
        if(n%2==0)op2=dp[i/2];
        op3=dp[i-1];
        dp[i]=min(min(op1,op2),op3) + 1;

    }
    return dp[i];
}

int main(){
    cout<<minSteps(4)<<endl;
    cout<<minStepsBU(4)<<endl;
}