//backedge -> an edge from a node that has path to it's ancestor, this is checked by the presence of ancestors in stack.
//for this we use a stack as an array implementation with access operations in O(1)

#include<bits/stdc++.h>

using namespace std;


class Graph{
    list<int> *l;
    int V;
    public:
        Graph(int V){
            this->V=V;
            l = new list<int>[V];
        }
        void addEdge(int x,int y,bool directed = true){
            l[x].push_back(y);
            if(!directed){
                l[y].push_back(x);
            }
        }
        bool cycle_helper(int node,bool* visited,bool* stack){

                visited[node]=true;
                stack[node]=true;
                
                for(auto nbr:l[node])
                {
                    if(stack[nbr]==true)return true;

                    else if(!visited[nbr]){
                        if(cycle_helper(nbr,visited,stack))return true;
                    }
                }

                stack[node] = false;
                return false;

        }

        bool contains_cycle(){
            
            bool* visited = new bool[V];
            bool *stack = new bool[V];
            return cycle_helper(0,visited,stack);
        }
};


int main(){
    //remember graph size is 1 based index and edges are 0 based
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);

    if(g.contains_cycle())cout<<"Yes"<<endl;
    else {cout<<"No"<<endl;}
}