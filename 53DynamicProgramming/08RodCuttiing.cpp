#include<bits/stdc++.h>
uusing namespace std;

int mp(int prices[],int n){
    
    if(n<=0)return 0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int cut = i+1;
        int ca = prices[i]+mp(prices,n-cut);
        ans = max(ans,ca);
    }
    return ans;
}

int mpBUP(int* prices,int n){
    int dp[n+1];
    dp[0]=0;
    
    for(int len=1;len<=n;len++)
        {
            int ans=INT_MIN;
            for(int i=0;i<len;i++){
                int cut=i+1;
                int ca = prices[i]+dp[len-cut]//this would be precomputed as it'd always be < len;    
                ans=max(ca,ans);
            }
            dp[len]=ans;
        }
        return dp[n];
}