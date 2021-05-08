#include<iostream>
using namespace std;

typedef long long ll;

//for union of n sets, add individual sets, then for intersection of even no
//of sets subtract it and for od add it.
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