#include<iostream>
using namespace std;

typedef long long ll;

//for union of n sets, add individual sets, then for intersection of even no
//of sets subtract it and for odd add it.
//|A U B U C U D| = |A| + |B| + |C| + |D| - |A^B| - |B^C| - |C^A|..... + |A^B^C|.....- |A^B^C^D|
//find out total no of nos less than 1000 divisble by any prime no less than 20

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    ll primes[]= {2,3,5,7,11,13,17,19};
    
    while(t--)
    {
        ll n;
        cin>>n;

        ll subsets = (1<<8)-1;
        ll ans=0;
        for(ll i=1;i<=subsets;i++){
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);

            for(ll j=0;j<=7;j++)
            {
                if(i&(1<<j)){
                    denom = denom*primes[j];
                }
            }
            if(setBits&1){
                ans += n/denom;
            }
            else{
                ans-= n/denom;
            }
        }
        cout<<ans<<endl;
    }
     
    return 0;
}