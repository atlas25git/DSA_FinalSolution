//dynamic array, grows and shrink when req.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //intialization:
    vector<int> a;
    int size = 5; int initializeWith =10;
    vector<int> b(size,initializeWith);

    vector<int> c(b.begin(),b.end());
    vector<int> d{1,2,3,4,5};

    //iteration
    //vectorName.size()->gives elements present

    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<"\n";
    }

    //using iterator
    cout<<"Using iterator"<<endl;
    for(auto it = c.begin();it!=c.end();it++)
    {
        cout<<*it<<"\n";
    }

    //for each:
    cout<<"ForEach"<<endl;
    for(int x:d){
        cout<<x<<"\n";
    }

    //v.push_back(x) used to add x at the end

    cout<<"Memory Comparisons"<<endl;
    b.push_back(11);
    cout<<"Stats for intialized size array d"<<"\n";
    cout<<d.size()<<endl; //elements inside
    cout<<d.capacity()<<endl; //capacity of underlying structure
    cout<<d.max_size()<<endl; //Max elemets that the vector could hold.

    cout<<"Stats for automatically expanded vector"<<"\n";
    cout<<b.size()<<endl; //elements inside
    cout<<b.capacity()<<endl; //capacity of underlying structure
    cout<<b.max_size()<<endl; //Max elemets that the vector could hold.
    //here we see that capacity becomes 10 given the fact that doubling happens in the case
    //vector is to be self expanded
}