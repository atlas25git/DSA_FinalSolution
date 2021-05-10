//For optimization in prime detection
//1) One could check for factors in range 2 to sqrt(N)

//Sieve Approach:
//Mark all the multiples of prime nos starting from 2, and
//then continuing for the ones which aren't marked
//for such primes start marking from P^2
//for p=5, p^2, coz others would already have been marked {1,2,3,4}
//skip all the even nos.
//complexity : N/2 + N/3 + ..... 
//O(NloglogN) ->approximately linear

#include<bits/stdc++.h>
using namespace std;

void prime_sieve(int* p){

    for(int i =3; i<=1000000;i+=2){
        p[i] = 1;
    }
    for(ll i =3; i<=1000000;i+=2){
        if(p[i]==1){

            for( ll j = i*i;j<=1000000; j= j+i){
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main(){
    int n;
    cin>>n;

    int p[1000005] = {0};
    prime_sieve(p);

    int csum[1000005]={0};

    fr(int i=1;i<=1000000;i++){
        csum[i] = csum[i-1] + p[i];
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<csum[b] - csum[a-1]<<endl;
    }
}
 