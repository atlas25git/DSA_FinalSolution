#include<bits/stdc++.h>
using namespace std;

void permute(char*in ,int i,set<string> &s){
    
    if(in[i]=='\0')
    {
        //cout<<in<<", ";
        string t(in);
        s.insert(t);
        return;
    }
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1,s);
        //BT
        swap(in[i],in[j]);
    }
    //swap are permanent we nee to restore them to OG state
    //this could be done by BT;

}

int main(){
    char in[100];
    cin>>in;
    set<string> s;
    permute(in,0,s);
    int z =s.size();
    cout<<z<<"----"<<"\n";
    
    for(auto str : s)
    cout<<str<<" , ";

    return 0;
}