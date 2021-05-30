#include<bits/stdc++.h>
using namespace std;

int a[10000];
int dp[10000][10000];

long long sum(int s,int e){
    long long ans = 0;
    for(int i=s;i<=e;i++){
        ans += a[i];
        ans %= 100;
    }
    return ans;
}


long long solveMixtures(int i,int j){
    if(i>=j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j] = min(dp[i][j],solveMixtures(i,k)+solveMixtures(k+1,j)+sum(i,k)+sum(k+1,j));
    }
}


 int main(){
     int n;
     while((scanf("%d",&n)!=EOF)){
         for(int i=0;i<n;i++)cin>>a[i];
         for(int i=0;i<=n;i++)
         {
             for(int j=0;j<=n;j++)dp[i][j]=-1;
         }
     }
     cout<<solveMictures(0,n-1)<,rndl;
 }