//Splitwise algorithm
#include<bits/stdc++.h>

using namespace std;

class person_compare{
    public:
    bool operator()(pair<string,int> p1, pair<string,int> p2){return p1.second<p2.second;}
};

int main(){
    int no_of_transactions,friends;
    cin>>no_of_transactions>>friends;
    
    string x,y;
    int amount;
    map<string,int> net;
    
    multiset<pair<string,int>,person_compare> m;
    for(auto p:m){
        string person = p.first;
        int amount = p.second;
        if(net[person]!=0){
            m.insert(make_pair(person,amount));
        }

    }

    int count=0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = low->second;
        string debit_person = low->first;

        int credit = high->second;
        string credit_person = high->first;

        m.erase(low);
        m.erase(high);

        int settled_amount = min(-debit,credit);
        debit += settled_amount;
        credit -= settled_amount;


        cout<<debit_person<<" Will Pay "<<settled_amount<<" to "<<credit_person<<endl;

        if(debit!=0)m.insert(make_pair(debit_person,debit));
        if(credit!=0)m.insert(make_pair(credit_person,credit));

    }

    return 0;
}