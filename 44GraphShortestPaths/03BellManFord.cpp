//4 pop algos-> out of 5 , 3 are sssp 
//1.BFS-> O(V+E) // O(n)
//2.Dijkstra->wtd graph with pos. edges -> O(ElogV) //O(nlogN)
//3.bellman ford -> wtd graph with negative edges -> O(V*E) //O(n^2)

//Floyd Wrshal: All oair shortest path
//BellMan Ford
//------------------------
//1) init each v with INT_MAX
//2)relax each edge v-1 times
//3)negative wt cycle dtection -> if present it'd be impossible to compute as minima would lead to -infinity
//BF is a dp based algorithm

//Sample testcase
// 3 3 
// 1 2 3
// 2 3
// 4
// 3 1 -10
    
//      3   
//   1----->2
// -10\    /  
//     \  /4
//       3
   

#include<bits/stdc++.h>
using namespace std;


vector<int> bellman_ford(int V,int src,vector<vector<int>> edges)
{   

       vector<int> dist(V+1,INT_MAX);
       dist[src]=0;

       for(int i=0;i<V-1;i++){
           for(auto edge : edges)
           {
               int u=edge[0];
               int v=edge[1];
               int wt=edge[2];

               if(dist[u]!=INT_MAX and dist[u]+wt<dist[v]){
                   dist[v] = dist[u]+wt;
               }
           }
       }

       for(auto edge:edges){
           int u=edge[0];
               int v=edge[1];
               int wt=edge[2];

           if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
               cout<<"Negatice wt cycle found";
           }
       }

       return dist;


}




int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    vector<int> dis = bellman_ford(n,1,edges);
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<" is at dist "<<dis[i]<<endl;
    }

    return 0;

}
