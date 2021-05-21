//sort edges in increasing order of wts
//add edge if no cycle exists in the graph, it could be added
//greedy algo

#include<bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> p;
    void init(int NN){
        p.clear();p.resize(NN);
        iota(p.begin(),p.end(),0);
    }
    int get(int x) return(x==p[x]?x:(p[x]=get(p[x])));

    void unite(int x,int y)x=get(x),y=get(y),if(x!=y)p[x]=y;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(i = 0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;x--,y--;
        edges[i]={w,x,y};
    }
    sort(edges.begin(),edges.end());
    dsu g;
    g.init(n);
    for(i =0;i<m;i++){
        int x=edges[i][1];
        int y=edges[i][2];
        int w=edges[i][0];
        if(g.get(x)!=g.get(y)){
            G.unite(x,y);
            ans+=w;
        }     
    }
    cout<<ans;
}

int main()
{
    solve();
}