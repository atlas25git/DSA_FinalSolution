//Min no of dice throws req to reach dest 36 from the  source 1, give the shortest path
//ladders give a positive jump and the snakes a jump of neg
//it's an unwtd graph, cause every edge costs same on dice nos.
//for a laddr that starts at 2 and takes one to 15, has a jump of +13
//in unwtd graphs lvl order traversal gives shortest dist to a node, and if it's wtd graph we use dijkstra's

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> l;
    
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            //l[y].push_back(x);
        }

        void bfs(T src, T dest){
            
            map<T,int> dist;
            queue<T> q;
            map<T,T>parent;
            

            for(auto node_pair : l){
                T node = node_pair.first;
                dist[node] = INT_MAX;
            }
            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            //visited[src]=true;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                //cout<<node<<" ";

                for(int nbr : l[node]){
                    if(dist[nbr] == INT_MAX)
                    {
                        q.push(nbr);
                        dist[nbr]=dist[node] + 1;
                        parent[nbr]=node;
                    }
                }
            }
            //for(auto node_pair: l)cout<<node_pair.first<<" Dist-> "<<dist[node_pair.first]<<endl;
            T temp = dest;
            while(temp!=src){
                cout<<temp<<"<--";
                temp=parent[temp];

            }
            cout<<dist[dest];
        }
};

int main(){

    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    
    Graph<int> g;
    for(int i=0;i<36;i++)
    {
        for(int dice=1;dice<=6;dice++){
            int j = i + dice;
            j  += board[j];

            if(j<=36)
                g.addEdge(i,j);//,cout<<"Called for i: "<<i<<" j "<<j<<"\n";
        }
    }
    g.addEdge(36,36);
    
    g.bfs(0,36);

}