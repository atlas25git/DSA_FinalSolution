#include<bits/stdc++.h>

using namespace std;

 int findk(int a[],int n,int key)
 {
     int s=0;
     int e=n-1;
     while(s<=e){
         int mid = (s+e)/2;
         if(a[mid] == key){
             return mid;
         }
         else if (a[s]<=a[mid]){
             if(key>=a[s] && key <=a[mid]){
                 e = mid-1;
             }
             else {
                 s = mid+1;
             }
         }
         else {
             if(key>=a[mid] && key < a[e]){
                 s=mid+1;
             }
             else e=mid-1;
         }
     }
     return -1; 
 }

 int main() {
     int n;
     cout<<"n"<<endl;
     cin>>n;
     cout<<"arr"<<endl;
     int a[1000];
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
     cout<<"key"<<endl;
     int key;
     cin>>key;
     cout<<findk(a,n,key);
     return 0;
 }