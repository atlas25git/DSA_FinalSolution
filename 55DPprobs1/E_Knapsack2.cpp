//HERE THE constraints are high as in w->10^9
//ITEMS 1TOn    ->SUBSET OF THEM WHOSE VALUE=v-> FIND   such a min wt
//dp[i,v] -> subsets from items 1 to i, st value of selected items =v,
//here we are making the dp array's second dimension based on the value of items
//
 
 #include<bits/stdc++.h>
 using namespace std;

#define inf 1e9+1

 struct item{
     int wt;
     int val;
 };

int solve(vector<item> ar,int n,int W)
 {  
     //max value for indiv elements->1000 hence for the case when all of them are selected.
     int maxVal = n*1000;
     int dp[n+1][maxVal+1];

     for(int val=0;val<=maxVal;val++)dp[1][val]=inf;
     dp[1][0]=0;
     dp[1][ar[1].val] = ar[1].wt;
     
     for(int i=2;i<=n;i++)
     {
         for(int v=0;v<=maxVal;v++)
         {
             dp[i][v] = dp[i-1][v];
             if(ar[i].val > v)continue;
             dp[i][v] = min(dp[i][v], ar[i].wt + dp[i-1][v-ar[i].val]);
         }
     }
     int ans=0;
    for(int x=0;x<=maxVal;x++)
    {
        if(dp[n][x]<=W)ans=x;
    }
    return ans;

 }

 int main()
 {
     int n,w;
     cin>>n>>w;
     vector<item> ar(n+1);
     for(int i=1;i<=n;i++)
     {
         cin>>ar[i].wt>>ar[i].val;

     }
     cout<<solve(ar,n,w);
 }