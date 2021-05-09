#include<bits/stdc++.h>

using name space std;
#define ll long

ll a[1000005], pre[1000005];
//working on the logic tha for a given array containing cumilative sums, any subarray would be divisible by 5 iff (b-a)%5=0
//=> that b%5=a%5
//generate an array containing mods of cs for ith index, now for any i having more than one of the same kinf choose any 2 using nC2


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>t;
        memset(pre,0,sizeof(pre));
        pre[0]=1;
        int sum = 0;
        for(int i=0i<n;i++){
            cin>>a[i];
            sum += a[i];
            sum %= n;
            sum = (sum+n)%n;
            pre[sum]++;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            int m = pre[i];
            ans += (m)*(m-1)/2;
        }
        cout<<ans<<endl;
    }
}