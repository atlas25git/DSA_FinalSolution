//used in probems like counting total no. of BSTs with given N bumbered nodes
//here ans is nth member of the catalan series:
//Formula 2nCn/n+1
//recursive relation
//bin tree instead of bst then n!Catalan no.
//oeis ->> to fin out all possible sequences

cpp_int findCatalan(int n) 
    {
        cpp_int dp[n+1];dp[0]=1;
        for(long long i=1;i<=n;i++)
        {dp[i] = (((2*i)*(2*i-1)*dp[i-1])/(i*(i+1)));} 
        
        return dp[n];
    }
