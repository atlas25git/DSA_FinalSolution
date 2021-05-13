#include<bits/stdc++.h>

using namespace std;

void move(int n,char src,char helper, char dest)
{
    if(n==0)return;
    move(n-1,src,dest,helper);
    //we now assume that n-1 disks have been moved to helper and now src contains 
    //just the biggest disk, which is now to be shifted to dest, hence the right position
    //following line signifies that we've placed the n'th disk right
    cout<<"Shift disk "<<n<<" from "<<src<<" to "<<dest<<endl; 
    move(n-1,helper,src,dest);

}

int main(){
    move(6,'A','B','C');
    return 0;
}