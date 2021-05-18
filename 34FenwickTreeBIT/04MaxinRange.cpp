//since it stores cumulative answers
//we could only query for max till a given index
//not of the lkes of l to r


#include<bits/stdc++.h>
using namespace std;

int a[100000];
int bit [100000];

void update(int i,int val,int N)
{
    while(i<=N){
        bit[i] = max(bit[i],val);
        i += (i&(-1));
    }
}

int query(int i){
    int ans = 0;
    while(i>=0)
    {
        ans = max(ans,bit[i]);
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
        update(i,a[i],n);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int i;
        cin>>l;
        cout<<query(l)<<endl;
    }
    return 0;
}