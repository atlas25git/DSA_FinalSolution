#include<bits/stdc++.h>

using namespace std;

int dTobin(int n){
    int ans =0;
    int p=1;

    while(n>0){
        int lb = (n&1);
        ans += p*lb;
        p=p*10;
        n=n>>1;
    }return ans;
}
int main(){
    cout<<dTobin(90)<<endl;
}