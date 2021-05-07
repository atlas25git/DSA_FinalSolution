#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
             PBDS;

bool cmp(string s1, string s2){
    if(s1.size() <= s2.size() && s2.substr(0,s1.size())== s1) return false;
    else if (s2.size() <= s1.size() && s1.substr(0,s2.size()) == s2) return true;
    else return s1<s2;

} 

int main(){

    int n;
    cin>>n;
    string s[n];
    int i=0;
    while(i<n)
    {
        cin>>s[i++];
    }
    sort(s,s+n,cmp);
    for(auto x: s)cout<<x<<endl;

}