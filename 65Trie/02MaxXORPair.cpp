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

class node{
    public:
    node* left;
    node* right;
};

class trie{
    
    node* root;
   
    public:
    trie(){
        root = new node();
    }
    void insert(int n){
        
        node* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left = new node();
                }
                temp = temp->left;

            }
            else{
                if(temp->right == NULL){
                    temp->right=new node();
                }
                temp = temp->right;
            }
        }
    }
    int max_xor_helper(int value){
        node* temp = root;
        int current_ans=0;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;
            if(bit==0)
            {
                if(temp->right!=NULL){
                    temp=temp->right;
                    current_ans+=(1<<j);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                    current_ans+=(1<<j);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(int* input,int n)
    {
        int max_xor=0;
        for(int i=0;i<n;i++)
        {
            int val=input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            cout<<current_xor<<" ";
            max_xor = max(current_xor,max_xor);
        }
        return max_xor;
    }
};

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    int  input[]={3,10,5,25,2,8};
    trie t;
    cout<<t.max_xor(input,6)<<endl;
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
            // int t;
            // cin>>t;
            // while(t--)
            solve();
        }
    }