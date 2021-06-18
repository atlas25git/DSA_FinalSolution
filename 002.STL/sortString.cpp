/***************************************
*****Solution authored by Atlas25.******
*****************************************/
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
void solve(){
    int i,j,k,n,m,ans1=0,cnt=0,sum=0;
        
        string s;
        getline(cin,s,'\n');
        char* ar;
        ar = &s[0];
        string ans="";
        char* p = strtok(ar," ");
        string x = p;
        sort(x.begin(),x.end());
        ans = x;
        cout<<x<<endl;
        
        
        while(p!=NULL)
        {   
            p=strtok(NULL," ");
            string x1 = p;
            sort(x1.begin(),x1.end());
            //cout<<x1<<endl;
            x =x +" "+ x1;
            
        }
        cout<<x.size()<<endl;

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
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }