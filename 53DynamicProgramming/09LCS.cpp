#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int i,int j){
    
    if(i==s1.length() || j==s2.length())return 0;
    if(s1[i]==s2[i])
    {
        return 1+lcs(s1,s2,i+1,j+1);
    }

    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);
    return max(op1,op2);


} 

//memoization

int lcs(string s1,string s2,int i,int j,vector<vector<int>> &dp){
    
    if(i==s1.length() || j==s2.length())return 0;

    if(dp[i][j]!=-1)return dp[i][j];


    if(s1[i]==s2[i])
    {
        return dp[i][j] = 1+lcs(s1,s2,i+1,j+1,dp);
    }

    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);
    return dp[i][j] = max(op1,op2);


}