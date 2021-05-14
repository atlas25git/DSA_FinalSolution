#include<bits/stdc++.h>

using namespace std;

//here we figure out a monotonic subspace to search for
//and mind it that this ain't stall positions
//but is the distance between them
//we check on the total given area apply bin search on it
//and check for the valdity of our mid over the stall locations

bool cowPlaced(int stalls[],int n,int c,int min_sep){
    int lc = stalls[0];
    int cnt =1;

    for(int i=1;i<n;i++){
        if(stalls[i]-lc>=min_sep){
            lc=stalls[i];
            cnt++;
            if(cnt == c) return true;
        }
    }
    return false;
}

int main(){
    int stalls[]={1,2,4,8,9};
    int n=5;
    int cows = 3;

    //bin
    int s=0;
    int e=stalls[n-1]-stalls[0];

    int ans = 0;
    while(s<=e){
        int mid = (s+e)/2;
        
        if(cowPlaced(stalls,n,cows,mid)){
            ans = mid;
            s=mid+1;
        }else{
            e = mid-1;
        }
    }
    cout<<ans<<endl;
}