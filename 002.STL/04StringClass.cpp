//alternative for char array
//wraps char array inside string class
//like a container

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s0;
    string s1("Hello");
    string s2 = "Hello";
    string s3(s2);
    string s4 = s3;

    char a[] = {'a','b','c','d','\0'};
    string s5(a);

    cout<<s0<<"\n";
    cout<<s1<<"\n";
    cout<<s2<<"\n";
    cout<<s3<<"\n";
    cout<<s4<<"\n";
    cout<<s5<<"\n";

    if(s0.empty()){
        cout<<"s0 empty"<<"\n";
    }

    //append
    s0.append("NotNull anymore");
    cout<<s0<<"\n";

    s0 += " Second wave";
    cout<<s0<<endl;

    //Remove
    cout<<s0.length()<<endl;
    s0.clear();
    cout<<s0.length()<<endl;

    //compare
    //int of equal =0, >1,<1
    //lexicographic comparison

    cout<<s1.compare(s0)<<endl;
    
    //overloaded operators < > == could also be used
    bool verdict = s5 > s5;
    
    cout<<verdict<<endl;

    //square brackets also defined
    cout<<s5[0]<<endl;

    //Find substrings
    string s = "Stalin says a million dead is just a statistics";
    int idx = s.find("dead");
    cout<<s<<endl;
    cout<<idx<<endl;

    //removing a word
    s.erase(idx,5);
    cout<<s<<endl;


    //iterating
    //simple for loop with s[i] notation

    //iterators

    for(auto it = s.begin();it!=s.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"\n";
    cout<<"forEach"<<"\n";
    //for each
    for(auto c:s){
        cout<<c<<".";
    }

}