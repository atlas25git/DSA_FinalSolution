#include<bits/stdc++.h>
using namespace std
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const mod = 1e9 + 7;
const int N = 100005, M=22;
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
            dp[i]=INT_MAX;

        for(int i=0;i<n;i++){
            for(int length=0;length<n;length++)
                if(dp[length]<a[i] && a[i]<dp[length+1])
                {
                    dp[length+1]=a[i];
                }   
        }
        int lis=0;
        for(int i=1;i<=n;i++)
            if(dp[i]!=INT_MAX)lis=i;
        cout<<lis;
}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt""w",stdout);
    #endif
}
int32_t main(){
    init();
        {
            int t;
            while(t--)
            solve();
        }
    }