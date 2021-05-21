//DAG only 
//Topological sorting: dependency graphs
//Linear ordering of steps
//maintain stack of dfs traversal, reverse the stack
//and print the elements by popping

//use a queue, insert the one with 0 in degree then as they're removed keep reducing the respective
//indegrees of its adjacent vertices.


#include<bits/stdc++.h>

using namespace std;

//template<typename T>
class Graph{
    
    list<int> *l;
    int V;
    
    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int x,int y){
            l[x].push_back(y);
            //l[y].push_back(x);
        }

        void topological_sort(){
            int* indegree = new int[V];

            for(int i=0;i<V;i++)indegree[i]=0;

            for(int i=0;i<V;i++){
                
                for(auto y: l[i]){
                    indegree[y]++;
                }
            }

            queue<int> q;
            for(int i=0;i<V;i++){
                if(indegree[i]==0)
                    q.push(i);
            }

            while(!q.empty())
            {
                int node = q.front();
                cout<<node<<" ";
                q.pop();

                for(auto nbr : l[node]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)q.push(nbr);
                }

            }
        }

        // void dfs_helper(T src, map<T,bool> &visited,list<T> &ordering)
        // {
        //     //cout<<src<<" ";
        //     visited[src]=true;

        //     for(T nbr: l[src]){
        //         if(!visited[nbr])
        //         {
        //             dfs_helper(nbr,visited,ordering);
        //         }
        //     }

        //     ordering.push_front(src);
        //     return;
        // }

        // void dfs(T src){
        //     map<T, bool> visited;
        //     list<T> ordering;

        //     for(auto p : l){
        //         T node = p.first;
        //         visited[node] = false;
        //     }

        //     for(auto p : l){
        //         T node = p.first;
        //         if(visited[node] == false)
        //         dfs_helper(node,visited,ordering);
        //     }

        //     for(auto node:ordering){
        //         cout<<node<<endl;
        //     }
            
        // }

        // void bfs(T src){
            
        //     map<T,int>visited;
        //     queue<T> q;
        //     q.push(src);
        //     visited[src]=true;
        //     while(!q.empty()){
        //         T node = q.front();
        //         q.pop();
        //         cout<<node<<" ";

        //         for(int nbr : l[node]){
        //             if(!visited[nbr])
        //             {
        //                 q.push(nbr);
        //                 visited[nbr]=true;
        //             }
        //         }
        //     }
        // }
};

int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.topological_sort();
    

}

