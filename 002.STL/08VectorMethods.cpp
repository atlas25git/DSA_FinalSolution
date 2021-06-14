//dynamic array, grows and shrink when req.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> d{1,2,3,4,5};

    d.push_back(15);
    d.pop_back();

    //inserting at an index at 0 based index
    d.insert(d.begin()+3,333);
    for(auto x: d)cout<<x<<endl;
    //inserting multiple no. with same value O(N)
    d.insert(d.begin()+3,4,444);
    for(auto x: d)cout<<x<<endl;

    //erase
    d.erase(d.begin()+3);
    for(auto x: d)cout<<x<<endl;
    //resize 
    d.resize(5);
    for(auto x: d)cout<<x<<endl;
    //clear 
    d.clear();
    
    //empty
    cout<<d.empty()<<endl;

    //d.front(), d.back() -> to give front most and last most
    //since doubling is costly operation we use reserve method to circumvent it from happening
    //frequently

    //v.reserve(1000);


    for(auto x: d)cout<<x<<endl;
}