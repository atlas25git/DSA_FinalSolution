#include<bits/stdc++.h>
using namespace std;

double f1(int r,int s,int p)
{
    if(r==0|| s==0) return 0.0;
    if(p == 0) return 1.0;
    if(dp[r][s][p] != -1.0)
        return dp[r][s][p];
    
    double tot = r*s + r*p + s*p;
    double ret = 0.0;

    ret+=f1(r-1,s,p)*((r*p)/tot); //paper kills rock
    ret+=f1(r,s-1,p)*((r*s)/tot); //rock kills scissor
    ret+=f1(r,s,p-1)*((s*p)/tot);
    return dp[r][s][p]=ret;

}

double f2(int r,int s,int p)
{
    if(p==0 || s== 0)return 0.0;
    if(r==0)return 1.0;

    if(dp[r][s][p]!= -1.0)return dp[r][s][p];

    double tot R*s + r*p + s*p;
    double ret =0.0;
    ret+=f2(r-1,s,p)*((r*p)/tot);
    ret+=f2(r,s-1,p)*((r*s)/tot);
    ret+=f2(r,s,p-1)*((s*p)/tot);

    return dp[r][s][p] = ret;
}

double f3(int r,int s,int p)
{
    if(p==0 || r== 0)return 0.0;
    if(s==0)return 1.0;

    if(dp[r][s][p]!= -1.0)return dp[r][s][p];

    double tot R*s + r*p + s*p;
    double ret =0.0;
    ret+=f3(r-1,s,p)*((r*p)/tot);
    ret+=f3(r,s-1,p)*((r*s)/tot);
    ret+=f3(r,s,p-1)*((s*p)/tot);

    return dp[r][s][p] = ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,s,p;
        cin>>r>>s>>p;
        set_dp();
        double ans1=f1(r,s,p);
        set_dp();
        double ans2=f2(r,s,p);
        set_dp();
        double ans3=f3(r,s,p);

        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
    return 0;
}