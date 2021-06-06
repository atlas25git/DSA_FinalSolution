//given graph find out all the path count of given length
//starting and ending at any 2 vertices
//dp(u)->no of paths starting at u and are of len k
//there sum would give the ans
//dp(u,j)->no of paths starting at u and of len k
//dp(u,j)= summation(c is a child of u)dp(c,j-1);
//final ans = sum(i=1 to N)dp(i,k)-> O(NK) soln

//88888888888888888888888888888888optimization8888888888888888888888888888888888888888888888888888888
//summation(no of paths of len k starting at some u and ending at v)
//representing this in the forrm of matrix
//ans will be sum of the entry of the matrix
//adj adjacency matrix -> 1 edge
//Ak[1,1] = summation(c=1 to N)Ak-1[1,x]*adj[x,1]
//Ak[i,j] = summation(x=1,N)Ak-1[i,x]*adj[x,i]
//Ak = Ak-1 * Adj
//A1 = all the paths which are of len 1 for any 2 pairs of verticces-> adj. Matrix
//A2 = A1*Adj
//A3= A2*Adj 
//=> Ak = (Adj)^k
//Now matrix exponentiation:
// A^k = A^(k/2) * A*(k/2)
//       A* A^(k/2) * A*(k/2) odd k
//TC = O(N3logK)
// Ans summation of Ak over all pair of i,j 

//code
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
    int n = A.size();
    vector<vector<ll>> res(n, vector<ll>(n,0));
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int x=0;x<n;x++)
                res[i][j]=(res[i][j] + A[i][x]*B[x][j])%mod;
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>> mat,ll exp)
{
    if(exp==1)
        return mat;
    vector<vector<ll>> res = power(mat,exp/2);
    if(exp&1)
        return multiply(multiply(mat,res),res);
    else return multiply(res,res);
}


ll solve(vector<vector<ll>>& adj,ll k, int n)
{
    vector<vector<ll>> ak = power(adj,k);
    ll ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans=(ans+ak[i][j])%mod;
    return ans;
}


int main(){
    int n;
    ll k;
    cin>>n>>k;
   
    vector<vector<ll>> adj(n,vector<ll>(n,0));
   
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>adj[i][j];

    cout<<solve(adj,k,n);
    return 0;
}
