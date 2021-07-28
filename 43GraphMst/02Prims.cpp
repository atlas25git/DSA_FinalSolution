//MST problem is defined for connected and undirected graphs.
//Maintains 2 subsets, in each iteration chooses the min wtd edge connecting the 2 sets.
//active edge -> either of the vertex should be a mst vertex
//MST edge -> edge inclued in MST
//mst vertex ->
//greedy algo local optimum -> global optimum

//Steps
//1 Choose a source vertex
//2 out of all the active edges choose the one with smallest wt.
//3 the added edge's neighbors would become active.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> gr[n+1];
    int vis[n+1]={};
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        gr[x].push_back({y,w});
        gr[y].push_back({x,w});
    }   
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    Q.push({0,1});
    long long int mst =0;
    while(!Q.empty()){
        pair<int,int> best Q.top();
        Q.pop();

        int weight = best.first;
        int to = best.second;

        if(vis[to]) continue;

        mst+=weight;
        vis[to]=1;
        for(auto x:gr[to]){
            if(vis[x.first]==0){
                Q.push({x.second,x.first});
            }
        }
        
    }
    cout<<mst<<endl;
}
