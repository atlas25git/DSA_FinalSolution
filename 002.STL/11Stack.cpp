#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    s.pop();
    cout<<s.empty()<<endl;


    return 0;
}