//given list of strings, sort them

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool cmp(string a,string b)
{
    if(a.length() == b.length())
    {
        return a<b; //in this case place the lexicographically smaller string first
    }
    return a.length()>b.length(); //greater in length would be placed first
}

int main()
{
    int n;
    cin>>n;
    cin.get();

    string s[100];

    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    cout<<"I/P given:"<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    //naive lexicographic sorting
    sort(s,s+n);
    cout<<"After solrting (Naive)"<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    //implementing custom sort
    sort(s,s+n,cmp);
    cout<<"After custom sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}
