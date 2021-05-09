//a^n -> a(a^(n/2))^2 if odd
//        (a^(n/2))^2


#include<bits/stdc++.h>
using namespace std;

int pow(int a,int n){
    if(n==0) return 1;

    int subprob = pow(a,n/2);

    if(n&1){
        return a*subprob*subprob;
    }
    return subprob*subprob;
}

int main(){
    int a,n;
    cin>>a>>n;
}