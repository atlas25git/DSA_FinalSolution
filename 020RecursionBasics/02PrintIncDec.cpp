#include<bits/stdc++.h>

using namespace std;

void incR(int n)
{
    if(n==0)return;
    //statement written after rec call works in bottom
    //up manner i.e, 0 to 1 but in stack's terminology 
    //it's top down 
    incR(n-1);
    cout<<n<<" ";
}

void decR(int n)
{
    if(n==0){
        return;
    }

    cout<<n<<" ";
    decR(n-1);
}

int main(){
    int n; cin>>n;
    incR(n);
    decR(n);
    return 0;

}