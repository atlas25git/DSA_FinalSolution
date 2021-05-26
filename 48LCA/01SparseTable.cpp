// In programming, a function is idempotent, when we can call it many times with the same arguments and the result won’t change beyond initial calling.
// It is close enough to the mathematical definition but instead of applying function, we execute it many times.

// Range-Query -> logN
// Idempotent fn -> using sparse table O(1);

//  st[i][j] will store the answer for the range [i,i+2j−1] of length 2j
//of we start at i for the length 2^j ->[i, i+2^j-1]
//the row indices contain starting points in the range, and the col indices-> length we are calculating for.
//so basicall for a query of range 0 to 2 elements would be given by 0,1->single element and 02->single element 
//it will increase in this fashion first col contains 1 len ranges, 2nd contains 2 len, third 4, etc;

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M=22;

struct sparse_table{
    vector<vector<int>> mat;
    int n,m;
    vector<int> p2;

    void init(int _n,int _m){
        n = _n;m=_m;
        mat.resize(n);
        p2.resize(n+1);
        for(int i=0;i<n;i++)mat[i].resize(m);
        for(int i=1;i<=n;i++)p2[i] = p[i/2]+1;

    }
    void build(int a[]){
        for(int i=0;i<n;i++)mat[i][0]=a[i];
        for(int j=1;j<m;j++){
            mat[i][j]=min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
        }
        
    }
    int query(int l,int r){
        int w = p2[r-1];
        return min(mat[l][pw], mat[r-(1<<pw)+1][pw]);
    }
};

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