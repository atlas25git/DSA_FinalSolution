
int seive(int n){
    int pr[n+1]={};
    vector<int> primes;
    int i,j;
    for(i=2; i<=n; i++){
        if(!pr[i]){
            primes.pb(i);
            for(j = i;j<=n;j+=i){
                pr[j]++;
            }
        }
    }

    int ans = 0;
    for(int i=2; i<=n;i++){
        if(pr[i] == 2)ans++;
    }
    return ans;
}