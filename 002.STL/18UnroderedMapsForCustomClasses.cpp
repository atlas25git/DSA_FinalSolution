#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

class student{
    public:
    string fn;
    string ln;
    string roll;

    student(string fn, string ln, string roll){
        this->fn = fn;
        this->ln = ln;
        this->roll = roll;
    }

    bool operator==(const student &s) const{
        return roll == s.roll?true:false;
    }

};

class HashFn{
    public:
    size_t operator()(const student &s) const{
        return s.fn.length() + s.ln.length();
    }
};

int main(){

    unordered_map<student,int,HashFn> smp;
     
    student s1("Stalin","Comrade","001");
    student s2("lenin","Grandpa","050");
    student s3("JFK","The Great","100");
    student s4("TDR","Stalwart","500");
    student s5("Stalin","Comrade","002");

    smp[s1]=1;
    smp[s2]=2;
    smp[s3]=3;
    smp[s4]=4;
    smp[s5]=5;

    for(auto s: smp){
        cout<<s.first.fn<<" "<<s.first.roll<<"\n"<<" Marks "<<s.second<<endl;
    }
}