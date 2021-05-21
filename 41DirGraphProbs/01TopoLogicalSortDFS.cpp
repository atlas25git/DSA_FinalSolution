//DAG only 
//Topological sorting: dependency graphs
//Linear ordering of steps
//maintain stack of dfs traversal, reverse the stack
//and print the elements by popping

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> l;
    
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void dfs_helper(T src, map<T,bool> &visited,list<T> &ordering)
        {
            //cout<<src<<" ";
            visited[src]=true;

            for(T nbr: l[src]){
                if(!visited[nbr])
                {
                    dfs_helper(nbr,visited,ordering);
                }
            }

            ordering.push_front(src);
            return;
        }

        void dfs(T src){
            map<T, bool> visited;
            list<T> ordering;

            for(auto p : l){
                T node = p.first;
                visited[node] = false;
            }

            for(auto p : l){
                T node = p.first;
                if(visited[node] == false)
                dfs_helper(node,visited,ordering);
            }

            for(auto node:ordering){
                cout<<node<<endl;
            }
            
        }

        void bfs(T src){
            
            map<T,int>visited;
            queue<T> q;
            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                cout<<node<<" ";

                for(int nbr : l[node]){
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
        }
};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.dfs(0);
    

}

