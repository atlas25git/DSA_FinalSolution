//Splitwise algorithm
#include<bits/stdc++.h>

using namespace std;

int main(){
    int no_of_transactions,friends;
    cin>>no_of_transactions>>friends;
    int x,y,amount;
    int net[100000] = {0};
    while(no_of_transactions--){
        cin>>x>>y>>amount;
        net[x] -= amount;
        net[y] += amount;
    }
    multiset<int> m;

    for(int i=0;i<friends;i++){
        if(net[i]!=0)m.insert(net[i]);
    }
    int cnt=0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());
        int debit = *low;
        int credit = *high;

        m.erase(low);
        m.erase(high);
        int settlement_amount = min(-debit,credit);
        cnt++;    
        debit += settlement_amount;
        credit -= settlement_amount;

        if(debit!=0)m.insert(debit);
        if(credit!=0)m.insert(credit);
    }
    cout<<cnt;
    return 0;
}