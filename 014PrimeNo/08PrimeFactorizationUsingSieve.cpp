//using sieve we will only go through the primes hence avoiding unnecessary
//computations

//Pre processing to build sieve, then normal loop computation
vector<int> factorize(int m,vector<int> &primes){

    vector<int> factors;
    factors.clear();

    int i=0;
    int p=primes[0];

    while(p*p<=m){
        if(m%p==0){
            factors.push_back(p);
            while(m%p==0)m=m/p;
        }
        i++;
        p=primes[i];
    }
    if(m!=1)factors.push_back(m);
    return factors;
}