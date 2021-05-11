// Euclid'd algorithm
//TC:
//------------------------------------
//T(n)=O(logN)


// GCD(a,b) = GCD(b,a%b)
// GCD(a,0) = a

//since gcd*lcm = a*b;
//we can thus easily calculate lcm of the inputs

#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main(){

    int a,b;;
    cout<<"Enter the values of a and b; :<<"\n;

    cin>>a>>b;

    cout<<gcd(a,b);
}