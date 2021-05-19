#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    unordered_map<string,list<pair<string,int>>> l;
    
    public:
        void addEdge(string x,string y, bool bidir, int wt)
        {
            l[x].push_back(make_pair(y,wt));
            if(bidir){
                l[y].push_back(make_pair(x,wt));
            }
        }
        void printAdjList()
        {
            for(auto p:l){
                string city = p.first;
                list<pair<string,int>> nbrs = p.second;

                cout<<city<<"->";
                for(auto nbr: nbrs){
                    string dest = nbr.first;
                    int dist = nbr.second;
                    cout<<dest<<" "<<dist<<",";
                }
                cout<<endl;

            }
        }
};

int main(){
    Graph g;
    g.addEdge("0","1",true,20);
    g.addEdge("0","2",true,20);
    g.addEdge("2","3",true,20);
    g.addEdge("1","2",false,20);
    g.printAdjList();
    

}