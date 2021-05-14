#include<bits/stdc++.h>
using namespace std;

void binarySrch(int *a,int n,int key)
{
    int s=0;
    int e = n-1;
    while(s<=e){
        int m = (s+e)/2;
        if(a[mid]==key)return mid;
        else if (a[mid]>key){
            e=mid-1;
        }
        else s= mid+1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int an[n];
    for(int i=0;i<n;i++)cin>>an[i];
    cout<<"enter key"<<"\n";
    int key; cin>>key;
    cout<<binarySrch(an,n,key);
} 