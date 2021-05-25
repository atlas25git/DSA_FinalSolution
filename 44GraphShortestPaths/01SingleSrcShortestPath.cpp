//dis calculated by BFS is the shortes in unwtd graph, having all the edges with same wts
//for directed we use dijkstra's

 #include <bits/stdc++.h>

 using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> l;
    
    public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        map<T,int> dist;
        queue<T> q;
       
        
        
        for(auto node_pair: l){
            T node = node_pair.first;
            dist[node] = INT_MAX:
        }
         q.push(src);
        visited[src]=0;
        while(!q.empty()){
            T node = q.font();
            q.pop();

            for(int nbr: l[node]){
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node+1];
                }
            }
        }

        for(auto np: l){
            T node = node_pair.first;
            int d= dist[node];
            cout<<"NODE "<<node<<" Dist from src "<<d<<endl;
        }

    }

};


int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,2);
    g.bfs(0);
    

}