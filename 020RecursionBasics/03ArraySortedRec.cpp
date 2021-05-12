#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n){

    if(n==0 || n==1)return true;

    if(a[0]<a[1] && isSorted(a+1,n-1))return true;

    return false;

}

//array is passed as a reference but the pointer which contains
//its elements is passed as value, so only the copy of this pointer
//variable is made

int main(){
    int arr[] = {1,2,3,4,9,6};
    int n =sizeof(arr)/sizeof(int);

    cout<<isSorted(arr,n)<<endl;
    return 99;
}