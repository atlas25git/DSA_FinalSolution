#include<bits/stdc++.h>

using namespace std;

int square_root(int n){
    int s=0;
    int e=n;
    float ans = -1;
    
    while(s<=e){
        int mid = (s+e)>>1;
        if(mid*mid ==n)return mid;
        if(mid*mid<n){
            ans = mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the no: "<<endl;
    cin>>n;
    cout<<"Sqrt "<<square_root(n);
}