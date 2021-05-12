#include<bits/stdc++.h>

using namespace std;

void bs(int a[], int n)
{
    if(n==1)return;

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    bs(a,n-1);
}

void bsRec(int a, int j, int n){
    if(n==1)return;

    if(j==n-1){
        return bsRec(a,0,n-1);
    }
    else if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }//inner loop

    bsRec(a,j+1,n);//outer loop
    return;
}