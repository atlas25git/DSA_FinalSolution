//used to store unique collection of elements, this one sorts them unordered version doesn't
//based on red b;ack tree, logN time insertion 
//can't upate first delete and then re insert

#include<iostream>
#include<set>

using namespace std;

int main(){
    int arr[] = {10,20,11,11,11,12,13,14};
    int n= sizeof(arr)/sizeof(arr[0]);

    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    for(auto it = s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    }

}
