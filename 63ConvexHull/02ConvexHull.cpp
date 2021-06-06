#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int mod = 1e9 + 7;
const int N = 100005, M=22;

struct point{
    int x,y;
    bool operator < (point &o){
        if(o.x == x)return y<o.y;
        else return x<o.x;
    }
    bool operator == (point &o){
        return (x==o.x && y==o.y);
    }
};

bool cw(point a,point b, point c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;   
}
bool ccw(point a,point b, point c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;   
}
bool collinear(point a,point b, point c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)==0;   
}

void convex_hull(vector<point>&p){
    if(p.size()<=2)return;

    sort(p.begin(),p.end());
    int i,n=p.size();
    point p1 = p[0], p2 = p[n-1];

    vector<point> up,down;
    up.pb(p1);
    down.pb(p1);
    for(int i=1;i<n;i++)
    {   //i==n-1 is for p2 which along with p1 is part of both the sets
        if(i==n-1 || !ccw(p1,p[i],p2)){
        while(up.size() >= 2 && ccw(up[up.size()-2], up[up.size()-1],p[i]))
            //happening for the points lying under the contour for the ones which are on the boundaries
            up.pop_back();
         up.pb(p[i]);
        }

        if(i==n-1 || !cw(p1,p[i],p2)){
        while(down.size() >= 2 && cw(down[down.size()-2], down[down.size()-1],p[i]))
            down.pop_back();
         down.pb(p[i]);
        }
    }
    p.clear();
    for(i=0;i<up.size();i++)
        p.pb(up[i]);
    for(i=0;i<down.size();i++)
        p.pb(down[i]);
    
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end()) - p.begin());

}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        vector<point> p(n);
        for(i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
        }
        map<pair<int,int>,int> mp;
        cin>>m;
        for(i=0;i<m;i++){
            point temp;
            cin>>temp.x>>temp.y;
            mp[{temp.x,temp.y}]++;
            p.pb(temp);
        }
        convex_hull(p);
        // for(auto x:p){
        //     cout<<x.x<<" "<<x.y<<'\n';
        // }
        //p contains all the points of convex hull
        for(auto x:p){
            if(mp.count({x.x,x.y})){
                cout<<"NO";
                return;
            }
        }
        cout<<"YES";
        return;
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
            //int t;
            //while(t--)
            solve();
        }
    }