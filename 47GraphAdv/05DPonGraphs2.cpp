#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M=22;

vector<int> gr[N];
int tin[N],tout[N],timer;
int dp[N];int depth[N];bool vis[N];

//dp(i) -> smallest no. node in subtree of i
//recurrence dp(i)min(i,min(dp(j))) j is child of i;

void dfs(int cur,int par,int dep){
    vis[cur]=1;
    dp[cur]=dep;
    depth[cur]=dep;

    for(auto x: gr[cur]){
        if(vis[x]==0){
            dfs(x,cur,dep+1);
            dp[cur]=min(dp[cur],dp[x]);
        }
        else if(x!=par){
            dp[cur]=min(dp[cur],depth[x]);
        }
    }
    
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
 
    //rooted at 1
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dp[i]<<'\n';
    }

}

void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int32_t main(){
    init();
    {
        solve();
    }
}