//odd cycled graphs can't be made bi partitie, all the even ones could be
//if there's a cycle, it mustn't be odd in length

#include<bits/stdc++.h>
using namespace std;

 
const int N = 100005, M=22;
vector<int> gr[N];
int vis[N];
bool odd_cycle = 0;

void dfs(int curr,int par,int col){
    vis[cur] = col;
    for(auto child: g[cur]){
        if(!vis[child])
        {
            dfs(child,cur,3-col);//3 - col, helps us with alternating the colors passed
        }
        else if(child != par && col == vis[child]){
            odd_cycle = 1;
        }
    }
    return;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);

    }
    dfs(1,0,1);

    if(odd_cycle)cout<<"yes"<<"\n";
    else cout<<"no\n";

}