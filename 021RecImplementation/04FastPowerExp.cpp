#include<bits/stdc++.h>

using namespace std;

int power(int a,int n){
    if(n==0) return 1;

    return a*power(a,n-1);
}

int fastPower(int a,int n){
    if(n==0)return 1;

    int sa = fastPower(a,n/2)//inefficient *fastPower(a,n/2);
    sa *= sa;//small scale memoization
    if(n&1) return sa*a;
    return sa;
}