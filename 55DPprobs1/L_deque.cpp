//players cold remove either of the 2 extremes
//Given following duress: X-Y maximize-> p1, X-Y minimize->p2
//it could be proved that both the players are trying to maximize their own scores
//as to maximize x-y we got to maximize the +ve quantity that is x, similarly to miniize x-y
//we will try to increase the abs value of yM 
//dp(i,j) -> optimal vlaue of X left with subarray [i,j]
//dp(i,j,turn)-> alternate turn value s 

//solution
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll dp[3001][3001][2];
ll solve(vector<int> &v,int i,int j,bool turn)
{
    if(i>j)return 0;
    if(dp[i][j][turn] != -1)return dp[i][j][turn];
 
  if(turn==1)
      return dp[i][j][turn] = max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));

   //for the player 2 we're taking the minimum of the values taken by x, i.e already stored in dp[i,j,1];
  else return dp[i][j][turn] = min(solve(v,i+1,j,1),solve(v,i,j-1,1)); 
}
 
int main(){
    int n;cin>>n;
    vector<int> v(n+1);
    memset(dp,-1,sizeof dp);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    ll scoreX = solve(v,1,n,1);
    ll scoreY = sum-scoreX;
    cout<<scoreX-scoreY;
    return 0;
}
 




#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dpt[3001][3001][2];
ll solve(vector<int> &v,int i,int j,bool turn)
{
    if(i>j)return 0;
    if(dpt[i][j][turn] != -1)return dpt[i][j][turn];

  if(turn==1)
      return dpt[i][j][turn] = max(v[i]+solve(v,i+1,j,0),v[j]+solve(v,i,j-1,0));
  //other player's turn
  else return dpt[i][j][turn] = min(solve(v,i+1,j,1),solve(v,i,j-1,1)); 
}
long long maximumAmount(vector<int> &arr, int n) 
{   
    //int sum=0;for(int i=0;i<n;i+=)sum+=arr[i];
    long long dp[n][n];
    //base case: Leading Diagonal
    for(int i=0;i<=n-2;i++)dp[i][i+1]=max(arr[i],arr[i+1]);
    
    for(int g =3;g<n;g+=2)//to keep track of increasing gaps over the rows
    {   //i keeps track of the rows
        for(int i=0;i+g<n;i++)
        //filling the respective diagonal values belonging to a particular gap len
        {   
            int j=i+g;
            dp[i][j] = max(
                    arr[i] + min(dp[i+2][j],dp[i+1][j-1]),
                    arr[j] + min(dp[i+1][j-1],dp[i][j-2])
                );
        }
    }
    //discerned from the original fn call parameters
    return dp[0][n-1];
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    memset(dpt,-1,sizeof dpt);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if(n==1){cout<<v[0]<<endl;
    return 0;
    }
    //ll scoreX = solve(v,1,n,1);
    ll scoreX = maximumAmount(v,n);
    //cout<<"scrx"<<scoreX<<endl;
    ll scoreY = sum-scoreX;
    cout<<scoreX-scoreY;
    return 0;
}

