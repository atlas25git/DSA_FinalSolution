#include<iostream>
using namespace std;

//in bit representation of power, multiplyb a raised to powers of these positions where
//there's a set bit.

int power_opt(int a, int n)
{
    int ans = 1;

    while(n>0){
        int lb = (n&1);
        if(lb){
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a,n;
    cin>>a>>n;
    cout<<power_opt(a,n);
    return 0;
}