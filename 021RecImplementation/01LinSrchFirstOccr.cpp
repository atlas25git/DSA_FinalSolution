#include<bits/stdc++.h>
using namespace std;

int firstOccr(int *a,int n,int key)
{   
     if(n==0)return -1;

     if(a[0]==key)return 0;
     
     int idx = firstOccr(a+1,n-1,key);
     return idx==-1?-1:idx+1;

}

int main(){
    int arr[] = {1,2,3,4,9,6};
    int n =sizeof(arr)/sizeof(int);

    cout<<firstOccr(arr,n,1)<<endl;
    return 99;
}