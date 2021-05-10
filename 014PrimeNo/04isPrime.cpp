//sieve has a limitation, 10^7, given no greater than that
//iterate in the sieve for 2 to sqrt(N), if any such present which divides
//then prime

bool isPrime( ll No)
{
    if(No <= n){
        
        return b[No] == 1 ?true:false;
    }
    for(ll int i=0; primes[i]*(ll)primes[i]<=No;i++){
        if(No%primes[i]==0)return false;
    }
    return true;
}