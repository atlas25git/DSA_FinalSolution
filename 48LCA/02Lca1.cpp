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
int Par[N],dep[N];

int lca_brute(int u,int v){
    if(u==v)return u;
    if(dep[u]<dep[v])swap(u,v);

    while(dep[u]>dep[v]){
        u=Par[v];
    }

    while(u!=v){
        u=Par[u];
        v=Par[v];
    }
    return u;
}


void dfs(int cur,int par){
    Par[cur]=par;
    for(auto x:gr[cur]){
        if(x!=par){
            dep[x]=dep[cur]+1;
            dfs(x,cur);
        }
    }
    return;
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
    cout<<lca_brute(1,9)<<"\n";
     
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