//to select 2 cities from diff components
// total no. of ways to select 2 cities from the total cites -no of ways to select 2 from cities in one component, for each of those

//using DSU
//for elements of a component do total vertices - rank of leader, this would give
//elements the member of this component could form pair with

//rank->no of nodes in the tree
//hence the one with lesser no of nodes would be required in the
//path compression step thus optimising the soln.
//as lesser skips would be required to reach the final parent;


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
            return parent[i] = findset(parent[i],parent);//path compression
        }

        void union_set(int x,int y,int parent[],int rank[])
        {
            int s1 = findset(x,parent);
            int s2 = findset(y,parent);

            if(s1!=s2)
                if(rank[s1]<rank[s2])
                parent[s1]=s2,rank[s2]+=rank[s1];

                else parent[s2]=s1,rank[s1]+=rank[s2];
        }



        //if both the vertices of an edge belong to the same set
        //it denotes that a cycle exists
        bool contains_cycle(){
            int *parent = new int[V];int *rank = new int[V];
            for(int i=0;i<V;i++)parent[i] = -1,rank[i]=-1;

            for(auto edge:l){
                int i = edge.first;
                int j=edge.second;

                int s1 = findset(i,parent);
                int s2 = findset(j,parent);

                if(s1!=s2)union_set(s1,s2,parent,rank);
                else return true;
            }
            delete [] parent;
            return false;

        }

        int pairing(){
            int* parent = new int[V];
            int *rank = new int[V];

            for(int i=0;i<V;i++){
                parent[i]=-1;
                rank[i] = 1;
            }

            int ans =0;
            for(auto edge : l){
                int i = edge.first;
                int j = edge.second;

                int s1 = findset(i,parent);
                int s2 = findset(j,parent);

                union_set(s1,s2,parent,rank);
            }
            for(int i=0;i<V;i++)ans+=V-rank[findset(i,parent)];
            return ans/2;

        }

};

int main(){
    Graph g(5);
    //g.addEdge(5,3);
    g.addEdge(0,1);
    g.addEdge(1,4);
    g.addEdge(2,3);
     if(g.contains_cycle())cout<<"Contains Cycle"<<endl;
     else cout<<"Nopes"<<endl;

     cout<<g.pairing()<<endl;

}