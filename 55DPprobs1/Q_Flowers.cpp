//monotonically increasing subseq with maximum sum
//approach for subseq qurs. think of the best subseq ending at i
//dp(i) sum of subseq ending at ith element and whose sum is max
//find out for K<i<=N
//give max dp(i) for all i
//dp(1)-> BTY(1);
//dp(i)-> only the ith element or some subseq that ended at some prev i's
//so under the given condn for index j, st j<i
//we're extending the subsequence therefore the given condn should also be observed
//hj<hi

//Recurrence:
// dp(i) = BTY(i)
//       = BTY(i) + dp(j){st j<i && hj<hi } max over all such js
//the given recurr is a O(N^2) soln as i depends upon 0 to i-1

//***********optimization***************************************
//if there is some j<i, dp[j]<dp[i], hj>hi
//for such indices there ain't any point in extending such indices as their dp[j]<dp[i]
//valid invalid indices:
//maintaining a set which could only hone valid indices
// we need a data str such  that  for i1,i2, hi1<hi2, dp[i1]<dp[i2] are only kept and rest are deleted
// For the case when we're extending some subseq, then only that index needs be extended which has the largest h smaller than ik
//all others won't be of use as highest height flower uptill now would already be a part of any subseq

//********************************CODE********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod= 1e9+7;

struct flower
{
    ll hi;
    ll bty;
};
 
ll solve(vector<flower>&v,int n)
{
    vector<ll> dp(n+1);
    map<ll,ll> meaningful;
    dp[1]=v[1].bty;
    meaningful[v[1].hi] = dp[1];
    ll ans=dp[1];
    for(int i=2;i<=n;i++)
    {
        dp[i] = v[i].bty;
        auto it = meaningful.lower_bound(v[i].hi+1);
        if(it != meaningful.begin())
        {
             it--;
            dp[i]+=it->second;     
        }
        meaningful[v[i].hi] = dp[i];
        it = meaningful.upper_bound(v[i].hi);
        while(it!=meaningful.end() && it->second<=dp[i])
        {
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it=temp;
        }
       ans=max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<flower>v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i].hi;
    for(int i=1;i<=n;i++)
        cin>>v[i].bty;
    cout<<solve(v,n);
    return 0;
}
