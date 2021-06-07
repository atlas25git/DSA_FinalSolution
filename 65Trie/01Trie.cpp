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

class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;

    Node(char d){
        data=d;
        terminal=false;
    }
};

class Trie{
    Node* root;
    int cnt;

    public:
    Trie(){
        root = new Node('\0');
        cnt=0;
    }
    void insert(char* w){
        Node* temp=root;
        for(int i=0;w[i];i++)
        {
            char ch = w[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp=n;
            }
        }
        temp->terminal=true;
    }

    bool find(char* w){
        Node* temp = root;
        for(int i=0;w[i];i++){
            char ch = w[i];
            if(temp->children.count(ch)==0)
                return false;
            else temp=temp->children[ch];
        }
        return temp->terminal;
    }
};

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    Trie t;
    char words[][10] = {"a","hello","not","news"};
    char w[10];
    cin>>w;
    for(int i=0;i<5;i++)
        t.insert(words[i]);
    if(t.find(w)){
        cout<<"PRESENT\n";
    }
    else cout<<"ABSENT\n";

    return 0;
        
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