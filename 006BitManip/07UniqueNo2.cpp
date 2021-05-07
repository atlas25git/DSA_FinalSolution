#include<bits/stdc++.h>
using namespace std;

//no. that occurs just once among given
//running xor, for the samenos it'd become 0, and for the distinct one would remain

int main(){

    int n;
    int a[100005];
    cin>>n;
    
    int no;
    int res = 0;

    for(int i=0;i<n;i++){
        cin>>no;
        a[i]=no;
        res=res^no;
    }
    int temp = res;
    int pos = 0;

    while((temp&1)!=1){
        pos++;
        temp = temp>>1;
    }

    int mask = (1<<pos);

    int x=0;
    int y=0;
    
    for(int i=0;i<n;i++){
        if((a[i]&mask)>0){
            x =x^a[i];
        }
    }
    y=res^x;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
    return 0;
}