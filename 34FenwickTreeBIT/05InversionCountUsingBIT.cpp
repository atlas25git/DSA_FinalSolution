//i<j but arr[i]><arr[j];
//O(NlogN)
//point update and range query

#include<bits/stdc++.h>
using namespace std;

int a[100000];
int bit [100000];

void update(int i,int inc,int N)
{
    while(i<=N){
        bit[i] += inc;
        i += (i&(-1));
    }
}

int query(int i){
    int ans = 0;
    while(i>0)
    {
        ans += bit[i];
        i -= (i&(-i));
    }
    return ans;
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //update(i,a[i],n);
    }
    int ans=0;
    for(int i=n;i>=1;i++){
        ans+=query(a[i]-1);
        update(a[i],1,n);
    }

    cut<<ans<<endl;
    return 0;
}