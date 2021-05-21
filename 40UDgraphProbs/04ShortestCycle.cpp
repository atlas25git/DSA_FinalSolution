//BFS -> mark dis to all other nodes
//start bfs from every vertex
//complexity - O(n^2)

#include<bits/stdc++.h>
using namespace std;


void bfs(int src,int n,int &ans){
    vector<int> dis(n+1,INT__MAX);
    queue<int> q;
    q.push(src);
    dis[src]=0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto nbr : gr[curr]){
            if(dis[nbr] == INT_MAX){
                dis[nbr]= dis[curr]+1;
                q.push(nbr);
            }
            else if(dis[nbr] >= dis[curr]){
                ans=min(ans,dis[nbr]+dis[curr]+1);
            }
        }

    }
}

void solve(){
    int i,j,n,m,ans;
    cin>>n>>m;
    for(i =0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push-back(x);
    }
    ans = n+1;
    for(i =1;i<=n;i++){
        bfs(i,n,ans);
    }
    if(ans==n+1)cout<<"no Cycle\n";
    else cout<<"Shotest cycle of len : "<<ans<<'\n';
}

int main()
{
    solve();
}