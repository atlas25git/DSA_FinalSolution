//dp[u]->len of longest path tht starts at u
//once we've dp[u] for all u(1,N),
//choose among it the one which is largest
//some nodes from u, v1,v2,v3...
//therefore dp[u] is atlest 1
//therefore we'll reduce the problem to the node's election,
//which has the highest dp[vi] $ i=0 to N
//dp[u]=1+max(dp(v))

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int dp[100001];

int solve(int src){
    if(dp[src]!=-1)return dp[src];
    bool leaf=1;
    int bestChild=0;
    for(int child:graph[src])
    {
        leaf=0;
        bestChild = max(bestChild,solve(child));
    }
    return dp[src] = leaf ?0:1+bestChild;
}

int main(){
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<m;i++)
    {
         int u,v;
         cin>>u>>v;
         graph[u].push_back(v);
}
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,solve(i));
    cout<<ans;

}