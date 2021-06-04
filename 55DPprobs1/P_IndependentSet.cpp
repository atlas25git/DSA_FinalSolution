//Remember not every tree is a binary tree
//Dp on trees
//no 2 adjacent vertices could be black calculate the total no of ways in which the vertices could be painted
//allowe colors: black and white
//arbitarily rooting the tree
//rooting at 1
//root-> paint black
//none of he chidren could be black then: white
//but if root-> white
//then children could be white or black

//Recurrences:
//dp(root,0) -> no of ways tree rooted at root(entire tree) could be painted under no restraints
//dp(u,0) -> ways to paint subtree rooted at node u, under no constraint that is it may beblack or white
//dp(u,1) -> u is under the constraint that it should be white as its parent is a black

//Final
//dp(u,0) = Product(st c is a child pf u)dp(c,1) //case where u is black
//        + Product(st c is a child of u)dp(c,0) //case where u is white
//dp(u,1) = Product(st c is a child of u)dp(c,0) // only the second case here corressponding to the duress put on u 
                                                // due to its parents
//Base Case:
//dp(leaf,0)=2
//dp(leaf,1)=1

//****************************************CODE**********************************************************************
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;

//tree[i]->nodes adj to i
vector<int> tree[100001];
ll dp[100001][2];

ll solve(int u,bool constraint, int pr)
{   
    if(dp[u][constraint]!=-1)return dp[u][constraint];
    ll ans=0;
    ll w1 =1;

    for(int child:tree[u])
    {
        if(child!=pr)
        {
            w1 = (w1*solve(child,0,u))%mod;
        }    
    }
    ans += w1;

    if(!constraint)
    {
        ll w2=1;
        for(int child : tree[u])
        {
            if(child!=pr)
                w2=(w2*solve(child,1,u))%mod;
        } 
        ans = (ans + w2)%mod; 
    }
        
   return dp[u][constraint] = ans;
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);

    }
    cout<<solve(1,0,-1);
    return 0;
}