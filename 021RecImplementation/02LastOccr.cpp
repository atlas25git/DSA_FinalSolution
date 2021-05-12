#include<bits/stdc++.h>
using namespace std;

int lastOccr(int *a,int n,int key)
{   
     if(n==0)return -1;

     int idx = lastOccr(a+1,n-1,key);
    
        if(idx != -1)return idx+1;
        else{
            if(a[0]==key)return 0;
            else return -1;
        }
     
     return idx;

}

int main(){
    int arr[] = {1,2,3,4,5,6,1};
    int n =sizeof(arr)/sizeof(int);

    cout<<lastOccr(arr,n,1)<<endl;
    return 99;
}