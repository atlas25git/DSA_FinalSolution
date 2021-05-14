#include<bits/stdc++.h>
using namespace std;

void frstOccrbinarySrch(int *a,int n,int key)
{
    int s=0;
    int e = n-1;
    int ans=-1;

    while(s<=e){
        int m = (s+e)/2;
        if(a[mid]==key)
        {
            ans = mid;
            e=mid-1;
        }

        else if (a[mid]>key){
            e=mid-1;
        }
        else s= mid+1;
    }
    return ans;//which will be the final updated value
}

void lastOccrbinarySrch(int *a,int n,int key)
{
    int s=0;
    int e = n-1;
    int ans=-1;

    while(s<=e){
        int m = (s+e)/2;
        if(a[mid]==key)
        {
            ans = mid;
            s=mid+1;
        }

        else if (a[mid]>key){
            e=mid-1;
        }
        else s= mid+1;
    }
    return ans;//which will be the final updated value
}

int main(){
    int n;
    cin>>n;
    int an[n];
    for(int i=0;i<n;i++)cin>>an[i];
    cout<<"enter key"<<"\n";
    int key; cin>>key;
    cout<<firstOccrbinarySrch(an,n,key);
    cout<<lastOccrbinarySrch(an,n,key);
} 