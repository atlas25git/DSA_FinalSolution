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
int tin[N],tout[N],timer;



void euler_tour_3(int cur, int par){
    
    cout<<cur<<" ";//entered the node cur;
    tin[cur] = ++timer;
    for(auto x: gr[cur]){
        if(x!=par){
            euler_tour_3(x,cur);   
        }
    }
    tout[cur] = timer;
    return;
}

bool is_ancestor(int x,int y){
    return tin[x]<=tout[y] && tout[x] >= tout[y];
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    timer= 1;//for all other

    cout<<"\nE3\n";
    //for euler 3rd:
    timer =0;  
    euler_tour_3(1,0);

    //this array of flattened tree could be used for various queries
    //change all the node value in subtree of 3 to 10
    //range update l,r being tin[node],tout[node]
    cout<<endl;
    for(i=1;i<=n;i++)
            cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;

    //if(is_ancestor(1,7))cout<<"yes\n";else cout<<"NO\n";


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