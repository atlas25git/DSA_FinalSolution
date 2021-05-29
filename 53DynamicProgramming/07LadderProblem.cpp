//+ -> or options
//* -> and options

int lp(int n,int k,int dp[])
{
    if(n==0)return 1;
    if(dp[n]!=0)return dp[n];
    int ways=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ways+=lp(n-i,k,dp);
        }
    }
    return dp[n]=ways;
}

int lpBUP(int n,int k){
    dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

//using sliding window
int optLPbup(int n,int k){
    int dp[100]={0};
    dp[0]=dp[1]=1;
    3
    for(int i=2;i<=k;i++)dp[i]=2*dp[i-1];//for the case where n-k<=0

    for(int i=k+1;i<=n;i++)dp[i]=2*dp[i-1] - dp[i-k-1];

    return dp[n];
}