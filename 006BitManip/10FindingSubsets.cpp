#include<bits/stdc++.h>
using namespace std;

void filterInt(int n, int a[])
{
    int j=0;
    while(n>0)
    {
        int lb = n&1;
        if(lb==1)cout<<a[j]<<" ";
        j++;
        n=n>>1;
    }
    cout<<endl;
}

void printSubsets(int* a)
{   
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2];
    //cout<<sizeof(*a)<<"Sizeofa "<<endl;
    //cout<<sizeof(a[1])<<"Sizeof a[0] "<<endl;
    int n = 4;//sizeof(a)/sizeof(a[0]);
    cout<<"size of arr: "<<n<<endl;
    //1 is already 2^0, hence right shift n posn raises is to power of n
    for(int i=0;i<(1<<n);i++)
    {   
        cout<<"Set no: "<<i<<endl;
        filterInt(i,a);
    }
}

int main(){
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a[]={1,2,3,4};

    int k = sizeof(a)/sizeof(a[0]);
    cout<<k<<endl;
   
    printSubsets(a);
}