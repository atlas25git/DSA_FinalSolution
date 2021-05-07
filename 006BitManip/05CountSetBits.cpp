#include<bits/stdc++.h>
using namespace std;

int countBits(int n){
//O(LogN)
    int ans = 0;
    while(n>0){
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}

int countBitsFast(int n){

    int ans = 0;
    while(n>0){
        n=n&(n-1);//this line removes last set bit, and no. of time loop runs is our ans.
        ans++;
    }
    return ans;
}

int main(){
    cout<<countBits(59)<<endl;
    cout<<countBitsFast(59)<<endl;
    cout<< __builtin_popcount(59)<<endl;
}