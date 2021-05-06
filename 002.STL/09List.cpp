//list -> DLL
//useful for insertion and deletion in middle
//push_back,push_front,pop_back,pop_front,insert,erase,remove

#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
     //inti
     list<int> l1{1,2,3,4,5};
     //diff DT
     list<string>l2 {"stalin","putin","rasputin","churchill"};
     l2.push_back("hitler");
     //print befor sort

     for(auto x: l2){
         cout<<x<<"--=";
     }
     cout<<"\n";

     //after sort
     l2.sort();

     for(auto x: l2){
         cout<<x<<"--<";
     }
    cout<<"\n";
     //reverse method
     //after sort
     l2.reverse();

     for(auto x: l2){
         cout<<x<<"-->";
     }



} 