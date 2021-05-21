#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;

    public:
        Graph(int V){
            this->V=V;
        }

        void addEdge(int u,int v){

            l.push_back(make_pair(u,v));
        }

        int findset(int i,int parent[])
        {
            if(parent[i]==-1)return i;
            return findset(parent[i],parent);
        }

        void union_set(int x,int y,int parent[])
        {
            int s1 = findset(x,parent);
            int s2 = findset(y,parent);

            if(s1!=s2)parent[s1]=s2;
        }



        //if both the vertices of an edge belong to the same set
        //it denotes that a cycle exists
        bool contains_cycle(){
            int *parent = new int[V];
            for(int i=0;i<V;i++)parent[i] = -1;

            for(auto edge:l){
                int i = edge.first;
                int j=edge.second;

                int s1 = findset(i,parent);
                int s2 = findset(j,parent);

                if(s1!=s2)union_set(s1,s2,parent);
                else return true;
            }
            delete [] parent;
            return false;

        }
};

int main(){
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
     if(g.contains_cycle())cout<<"Contains Cycle"<<endl;
     else cout<<"Nopes"<<endl;

}