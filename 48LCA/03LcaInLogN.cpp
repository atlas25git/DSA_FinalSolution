//lca-> depth wise last common node occurring in the traversal of given nodes.
//O(n)->approach

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
int Par[N][M],dep[N];




void dfs(int cur,int par){
    //Par[cur]=par;
    for(auto x:gr[cur]){
        if(x!=par){
            dep[x]=dep[cur]+1;
            dfs(x,cur);
        }
    }
    return;
}

void cal_sparse_table(int cur,int par)
{
    Par[cur][0]=par;
    for(int j=1;j<M;j++){
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    }
    for(auto x: gr[cur]){
        if(x!=par){
            cal_sparse_table(x,cur);
        }
    }
}

int LCA_using_depth(int u,int v){
    if (u==v)return u;

    if(dep[u]<dep[v])swap(u,v);
    int diff = dep[u]-dep[v];

    for(int i=M-1;i>=0;i--){
        if((diff>>i)&1){
            u=Par[u][i];
        }
    }
    if(u==v)return u;

    for(int i=M-1;i>=0;i--){
        if((Par[u][i] != Par[v][i]){
            u=Par[u][i];
            v=Par[v][i];
        }
    }

    return Par[u][0];

}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,0);
    cal_sparse_table(0,1);
     
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