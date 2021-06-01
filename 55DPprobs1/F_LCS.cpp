#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define prDouble(x) cout<<setprecision(10)<<x;
#define triplet pair<ll,pair<ll,ll>>
#define MAX 3000
int dp[MAX+1][MAX+1];

string getLCS(string& s,string& t,int len){
   
    //cout<<len<<endl;
    string LCS;
    int i=0,j=0;

    while(len>0){
        if(s[i]==t[j])
        {
            LCS.push_back(s[i]);
            i++,j++,len--;
        }
        else
        {
            if(dp[i][j+1]>dp[i+1][j])j++;
            else i++;

        }
        
    }
    return LCS;
}

int lenLCS(string &s,string &t,int i,int j)
{
    if(i>=s.length() || j>=t.length())
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==t[j]) 
        return dp[i][j]= 1+lenLCS(s,t,i+1,j+1);

    else 
        {return dp[i][j] = max(lenLCS(s,t,i,j+1),lenLCS(s,t,i+1,j));}
}

string solve(string s,string t){
    memset(dp,-1,sizeof(dp));
    int len=lenLCS(s,t,0,0);
    //cout<<len<<"___fn"<<endl;
    return getLCS(s,t,len);
}

int main(){
    string s,t;
    cin>>s>>t;
    //cout<<s<<t;
    cout<<solve(s,t);
}