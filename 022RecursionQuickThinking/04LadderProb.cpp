#include<bits/stdc++.h>

using namespace std;

//n steps jumps:{1,2,3}
//for the student to reach last step
//following are the options
//f(n) = f(n-1) + f(n-2) + f(n-3); 

//rec cals to n denote total no. of ways to reach n, it could be combination of 
//the 3 paradigms given

int f(int n,int k){
    if(n==0)return 1;//means a possible combination of steps
    
    //this one denotes not a possible set
    if(n<0) return 0;

    int ans = 0;
    for(int i=1;i<=k;i++)
    {
        ans+=f(n-i,k);
    }
    return ans;
}

int main(){
    cout<<f(4,3);
}