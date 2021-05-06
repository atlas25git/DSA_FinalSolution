//seperate chaining technique if hashing, based on hashing
//insertion del in O(1)
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<string,int> m;

    //Insert
    //1
    m.insert(make_pair("Stalin",55));

    //2
    pair<string,int> p;
    p.first="hitler";
    p.second=40;
    m.insert(p);
    
    //3
    m["FDR"] = 74;

    //2.Search

    string key = "Stalin";

    auto it = m.find(key);
    if(it!=m.end()){
        cout<<"key is present"<<" vale is "<<m[key]<<endl;
    }
    else{
        cout<<"Can't find "<<key<<endl;
    }

    //Map stores only the unique keys
    //m.count() -> 0 if not present, 1 if present.
    m.erase(key);
    if(m.count(key))cout<<"Found "<<m[key]<<endl;
    else cout<<"Not Found";

    //update
    m["hitler"] += 29;
    m["jFK"] = 45;
    for(auto it = m.begin(); it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }
    //keys are sorting criteria under the hood in lexicographic order
}