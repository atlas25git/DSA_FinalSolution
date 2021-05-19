#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1,pair<int,int> p2){
    return p1.first>p2.first;
}

int main(){
    int n,t,x,d,f,D,F,prev=0;
    cin>>t;
    while(t--){
        int flag=0,ans=0;
        vector<pair<int,int>> v;
        priority_queue<int> pq;

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        sort(v.begin(),v.end(),compare);
        cin>>D>>F;
        for(int i=0;i<n;i++){
            v[i].first = D- v[i].fist;
        }

        prev = 0;
        x = 0;

        while(x<n){
            if(F>=(v[x].first - prev))
            {
                F=F-(v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else{
                if(pq.empty()){
                    flag=1;
                    break;
                }
            
            F += pq.top();
            pq.pop();
            ans += 1;
            continue;
            } 
            x++;
        }
        if(flag==1)cout<<-1<<endl,continue;

        D = D - v[n-1].first;
        if(F>=D)cout<<ans<<endl,continue;

        while(F<D){
            if(pq.empty())flag=1,break;

            F += pq.top();
            pq.pop();
            ans = ans+1;
        }
        if(flag ==1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}