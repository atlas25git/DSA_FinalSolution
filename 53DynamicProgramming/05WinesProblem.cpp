//p[i] -> price of ith bottle
//Approach Top Down:
// MAX[ p[i]*y + f(i+1,y+1)
//       p[j]*y + f(i,j-1,y+1)
//      ]

//Bottom UP:

//we'll use a 2d array

#include<bits/stdc++..h>
using namespace std;

int profit(int winse[],int i,int j,int y,int dp[][]){
    
    if(i>j)return 0;
    if(dp[i][j]!=0)return dp[i][j];
    int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
    int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);
    dp[i][j] = max(op1,op2);
    return max(op1,op2);
}

int main(){
    int wines[]={2,3,4,1,5};
    int n=sizeof(wines)/sizeof(int);
    inty=1;
    int dp[100][100]={0};
    cout<<profit(wines,0,n-1,y,dp);
    return 0;
     
}