//vertex: if removing it from the graph, increases the no. of connected components
//^articulation point
//bridge: the edge whose removal ensures that the no of components increase
//lowest time: since backedges are the ones which point to already visited node not being parent,
//lowest time is defined for a node as the vertec with min discovery time which is reachable,
//through the given node's back edge



#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M=22;

vector<int> gr[N];
int disc[N],low[N],tme;
vector<int> art_p;
vector<pair<int,int>> bridge;

//dp(i) -> smallest no. node in subtree of i
//recurrence dp(i)min(i,min(dp(j))) j is child of i;

void dfs(int curr,int par){

    disc[curr] = low[curr]=tme++;
    int no_child = 0;
    for(auto child:gr[curr])
    {
        if(desc[chid]==0){
            dfs(child,curr);
            no_child++;
            low[curr] = min(low[curr],low[child]);

            if(par!=0 && low[child]>=disc[curr])art.pb(curr);//equal to case coz it's the vertex not edge that we're talking about

            if(low[child]>disc[curr]){
                bridge.pb({curr,child});
            }

        }
        else if(child!=par){
            low[curr] = min(low[curr],disc[child]); 
        }
    }

    if(par == 0 && no_child>=2)art_p.pb(curr);//for child<2-> no of components won't increase.

    return;
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
 
    //rooted at 1
    tme=1;
    dfs(1,0); 
    for(auto x: art_p)cout<<x<<" ";

}

void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int32_t main(){
    init();
    {
        solve();
    }
}