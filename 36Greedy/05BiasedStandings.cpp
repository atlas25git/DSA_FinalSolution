//implementation using count sort, since the ranks are in a range -> O(n)
//increment the indices of various ranks desired
//for each index i, calculate its badness by subtracting actual rank from the next possible rank, and keep decrementing the value@count sort array. 

#include<bits/stdc++.h>

using namespace std;



int main(){ 
    int arr[100000] = {0};
    int t;
    cin>>t;

    while(t--){
        memset(arr,0,sizeof orr);
        string name;
        int n,rank;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>name>>rank;
            arr[rank]++;
        }
        int actual_rank = 1;
        int sum =0;
        for(int i=1;i<=n;i++){
            while(arr[i]){
                sum+=abs(actual_rank,i);
                arr[i]==;
                actual_rank++;
            }

        }
        cout<<sum<<endl;
    }

}