//Given i stones in the pile
//dp(i): i stones in the pile, if the player making the move is able to win thwn 1 else it's 0
//dp(k): 1->player about to make 1 move will win
//dp(0)=0 -> losing state
//dp(x)=1 if dp(x-ai)=0 for all ai else 0
//here the no of moves is given by N and these N nos also describe the vakid moves
//moves vector is given in a sorted order


#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>& v, int k){
    //v represents the valid moves set
    bool dp[k+1];//representing the states of pile 0 to K
    memset(dp,0,sizeof dp);

    for(int i=1;i<=k;i++)
    {
        for(int move:v)
        {
            if(move>i)continue;
            if(dp[i-move]==0)dp[i]=1;
        }
    }    
    return (dp[k]) ? "First" : "Second";
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=1;i<=n;i++)cin>>v[i];
    cout<<solve(v,k);
    return 0;
}