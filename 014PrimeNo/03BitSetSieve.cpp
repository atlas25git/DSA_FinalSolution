//space optimized version of Sieve of Erastosthenes
//bitset<100> b; -> special class that uses bits in place of bytes(bool) to store elements, 
//space optimization of 8 times

#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

const int n =10000000;
bitset<10000005> b;
vector<int> primes;

void sieve(){
    b.set();//1.1.1.1.1
    b[0] = b[1] =0;
    for(ll i=2;i<=n;i++){
        if(b[i]){
            primes.push_back(i);
            for(ll j = i*i;j<=n;j=j+1){
                b[j]=0;
            }
        }
    }
}

int main(){

}