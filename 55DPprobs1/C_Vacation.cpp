//brute force
//consider doing and trying all the activites-> TC -> exponential
//3.2.2.2.2... -> 3.2^n-1

//thought process-> best poossible answer if boys does A/B/C on day N, and taking the maximum
//option (1,2,3)

//thinking about days 1 to N-1, for the case A/B/C done on Nth day
//dp[N][0]->max poss happiness for days 1 to n, given he did A on day n
//dp[N][1]
//dp[N][2]
//final ans=max_of_the_three
//dp[N][0] = an + max(dp[N-1][1], dp[N-1][2]);
//dp[N][1] = bn + max(dp[N-1][0], dp[N-1][2]);
//dp[N][2] = cn + max(dp[N-1][1], dp[N-1][0]);
//hence the recurrence would be: 
// dp[i][j] = ai + max(dp[i-1][1],dp[i-1][2])
//base case
//when there is just one day
//dp[1][0] = a,dp[1][1]=b,dp[1][2]=c;
//max of these;


#include<bits/stdc++.h>
using namespace std;

struct activity{
    int A,B,C;
}; 

int solve(vector<activity> ar,int n)
{
    int dp[n+1][3];
    dp[1][0]=ar[1].A;
    dp[1][1]=ar[1].B;
    dp[1][2]=ar[1].C;

    for(int i=2;i<=n;i++)
    {
        dp[i][0]=ar[i].A + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=ar[i].B + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=ar[i].C + max(dp[i-1][1],dp[i-1][0]);
    }


    return max(dp[n][0],max(dp[n][1],dp[n][2]));
}


int main(){
    int n,k;
    cin>>n;
    vector<activity> ar(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i].A;
        cin>>ar[i].B;
        cin>>ar[i].C;
    }
    cout<<solve(ar,n);
}