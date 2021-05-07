#include<bits/stdc++.h>
using namespace std;

//no. that occurs just once among given
//running xor, for the samenos it'd become 0, and for the distinct one would remain

int main(){

    int n;
    cin>>n;
    int no;
    int ans=0;

    for(int i=0;i<n;i++){
        cin>>no;
        ans=ans^no;
    }
    cout<<"UniqueNo: "<<ans<<endl;

    return 0;
}