//used to store multiple elements of same value, this one sorts them unordered version doesn't
//based on red b;ack tree, logN time insertion 
//can't upate first delete and then re insert
//based on bst
//assosciative cont. elements referred by their values


#include<iostream>
#include<set>
using namespace std;

typedef multiset<int>::iterator It;



int main(){
    int arr[] = {10,20,11,11,11,12,13,14};
    int n= sizeof(arr)/sizeof(arr[0]);

    multiset<int> s(arr,arr+n);
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    for(auto it = s.begin();it!=s.end();it++){
        cout<<*(it)<<",";
    }

//count of any element
cout<<endl;
cout<<s.count(11)<<endl;

//Erase->all occurrences 
//s.erase(11);
cout<<s.count(11)<<endl;

//find
auto it = s.find(12);
cout<<*it<<endl;
//all elemets equal to x
pair<It,It> p = s.equal_range(11);

for(auto it = p.first;it!=p.second;it++){
    cout<<*it<<" _ ";
}
//printing elemets within a given range

for(auto it=s.lower_bound(10);it!=s.upper_bound(77);it++){
    cout<<*it<<".";
}
}
