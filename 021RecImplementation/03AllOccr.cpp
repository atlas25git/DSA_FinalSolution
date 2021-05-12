#include<bits/stdc++.h>
using namespace std;

void allOccr(int *a,int i,int n,int key)
{   
     if(i==n)return;
     if(a[i]==key)cout<<a[i]<<" ";
     allOccr(a,i+1,n,key);

}

int main(){
    int arr[] = {1,2,3,4,5,6,1};
    int n =sizeof(arr)/sizeof(int);

    cout<<allOccr(arr,0,n,1)<<endl;
    return 99;
}