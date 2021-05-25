//all pair shortest path
//dijkstra and bellman ford give shortest path from single source
//d and b need to be run v times for all pairs
//dp based algo -> works with negative wts, can detect neg wt cycle like bell man ford
//in each itration out of V, we fill in the 2d , matrix whose i,j cell denotes
//path length possible from  to j using the iteration as a path member

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph)
{
        vector<vector<int>> dist(graph);
        int V=graph.size();   
         for(int k=0;k<V;k++){
             for(int i=0;i<V;i++){
                 for(int j=0;j<V;j++){
                     if(dist[i][j] > dist[i][k]+dist[k][i]){
                         dist[i][j] = dist[i][k] + dist[k][j];
                     }
                 }
             }
         }
         return dist;
}

int main(){
    vector<vector<int>> graph = {
                                {0,INT_MAX,-2,INT_MAX},
                                {4,0,3,INT_MAX},
                                {INT_MAX,INT_MAX,0,2},
                                {INT_MAX,-1,INT_MAX,0}
                                };
    
    auto res = floyd_warshall(graph);
    for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res.size();j++)
                cout<<res[i][j]<<" ";
            
cout<<endl;}
    return 0;
}