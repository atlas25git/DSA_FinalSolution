#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define M 1000000007

void multiply(int *a), int &n,int no)
{
    int carry =0;
    for(int i=0;i<n;i++){
        int product = a[i]*no + carry;
        a[i] = product%10;
        carry = carry/10;
        n++;
    }
    while(carry){
        a[n] = carry%10;
        carry = carry/10;
        n++;
    }
}

void bigF(int n)
{   
    int *a = new int[1000];
    for(int i=0;i<1000;i++){
        a[i] = 0;
    }
    a[0]=1;
    int n = 1;

    for(int i=2;i<=n;i++){
        multiply(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    delete []a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ll t;
    cin>>t;
    

}

----------------------------------------
python

n = int(input())

ans = 1

for i in range(1,n+1):
ans=ans*1