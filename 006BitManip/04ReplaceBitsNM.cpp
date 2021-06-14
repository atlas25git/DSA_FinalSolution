#include<bits/stdc++.h>
using namespace std;

//given 2 32 bit nos we've to set the i to j positions of N with M

int clearRangeItoJ(int n,int i, int j){

    int ones = (~0);//or -1 ~0 = -1
    int a = ones<<(j+1);
    int b = (1<<i) - 1;//last odd of  a complete 2 power set, all 1s 1 at i+1th pos -1 would give i 1s,
    int mask = a| b;
    int ans = n & mask;
    return ans;
}

int replaceBits(int n,int m, int i ,int j){
    int n_ = clearRangeItoJ(n,i,j);
    int ans = n_ | (m<<i);
    return ans;
}

int main(){

    cout<<replaceBits(15,2,1,3)<<endl;
}