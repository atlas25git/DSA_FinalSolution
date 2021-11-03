//single src shortest path for dir wtd graphs with no negative wt cycles

//in unwtd graphs lvl order traversal gives shortest dist to a node, and if it's wtd graph we use dijkstra's
//min ist using priority queues or sets->remove and insert up8d pair

//Doesn't work for neative wtd edges as to compute (a+b) while minimizing under the duress that b<0 & a>0,
//it requires us to select a as max as possible, which conflicts with the local greedy strategy of selecting the minima.
//O(VlogV) + O((V+E)logV) = O((V+E)logV)


#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{
    
    unordered_map<T ,list<pair<T,int>>> m;
    
    public:
        void addEdge(T u, T v,int dist,bool bidir=true){
            m[u].push_back(make_pair(v,dist));

            if(bidir)m[v].push_back(make_pair(u,dist));
        }

        void printAdj(){
            for(auto j: m){
                cout<<j.first<<"-> ";

                for(auto l:j.second){
                    cout<<"("<<l.first<<" . "<<l.second<<" ) ";
                }
                cout<<endl;
            }
        }

        void dijkstraSSSP(T src){
                unordered_map<T, int>dist;

                for(auto j:m){
                    dist[j.first] = INT_MAX;
                }

                set<pair<int,T>> s;
                dist[src]=0;
                s.insert({0,src});

                while(!s.empty()){
                    auto p = *s.begin();
                    T node = p.second;

                    int nodeDist = p.first;
                    s.erase(s.begin());

                    for(auto childPair: m[node]){
                        if(nodeDist+childPair.second < dist[childPair.first]){

                                T dest = childPair.first;
                                auto f = s.find({dist[dest],dest});
                                if(f!=s.end()){
                                    s.erase(f);
                                }

                                dist[dest] = nodeDist + childPair.second;
                                s.insert(make_pair(dist[dest],dest));


                        }
                    }
                    
                }
                for(auto d:dist){
                        cout<<d.first<<" is located at dist of "<<d.second<<endl;
                    }
                
        }
};

int main(){

    Graph<string> i;
    i.addEdge("a","d",1);
    i.addEdge("a","j",4);
    i.addEdge("j","d",2);
    i.addEdge("j","m",8);
    i.addEdge("b","a",2);
    i.addEdge("m","b",3);
    i.addEdge("a","d",3);
    i.addEdge("a","m",3);
    i.printAdj();
    i.dijkstraSSSP("a");

}
