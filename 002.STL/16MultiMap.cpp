//same as map but extends the limitations that only unique keys would be present, here more than 1 can exist
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    multimap<char,string> m;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        char ch;
        string s;
        cin>>ch>>s;
        m.insert(make_pair(ch,s));
    }

    //erase
    auto it = m.begin();
    m.erase(++it);

    for(auto p:m){
        cout<<p.first<<" -> "<<p.second<<endl;
    }

    //lb and ub
    auto itl = m.lower_bound('c');
    auto itu = m.upper_bound('c');
    for(auto itt=itl;itt!=itu;itt++){
       
        cout<<itt->first<<" "<<itt->second<<endl;
    }

    cout<<"number of c keys"<<endl;
    int count=0;
    for(auto itt=itl;itt!=itu;itt++){
       
        count++;
    }

    cout<<count<<endl;

    //search
    auto f = m.find('c');
    //now f could be accessed using first and second;

}   