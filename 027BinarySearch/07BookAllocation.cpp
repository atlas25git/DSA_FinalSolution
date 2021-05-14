#include<bits/stdc++.h>
using namespace std;

 bool isPossible(int arr[],int n,int m,int curr_min){
     int sU=1;
     int pg=0;

     for(int i=0;i<n;i++){
         if(pg+arr[i]>curr_min)
         {
             su++;
             pg=arr[i];
             if(su>m){
                 return false;
             }
         }
         else pg+=arr[i];
     }

     return true;
 }

 int findPage(int arr[],int n,int m){
     long long sum = 0;

     if(n<m)return -1;

     for(int i=0;i<n;i++)sum+=arr[i];

     int s=arr[n-1];
     int e=sum;
     int ans = INT_MAX;

     while(s<=e){
         int mid = (s+e)/2;
         if(isPossible(arr,n,m,mid)){
             ans = min(ans,mid);
             e=mid-1;
         }
         else{
             s=mid+1;
         }
         return ans;

     }
 }

 int main(){
     int t;
     cin>>t;

     for(int i=0;i<t;i++){
         int n,m;
         cin>>n>>m;

         int arr[1000];
         for(int j=0;j<n;j++)cin>>arr[j];
         cout<<findPage(arr,n,m)<<endl;
     }


 }