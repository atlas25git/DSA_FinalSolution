#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
             PBDS;

//Pbds->findByOrder||findByKey
            
int main(){
    PBDS st;
    st.insert(1);
    st.insert(20);
    st.insert(3);
    st.insert(11);
    st.insert(14);

    for(int i=0; i<st.size();i++){
        cout<<i<<" "<<*st.find_by_order(i)<<'\n';
    }
    //insertion and lookup both take just logn time

    cout<<"No. of elements smaller than the given no are: "<<st.order_of_key(115)-1<<endl;
}

//we can use the data str pair <int,int> in place of <int> to implement multiset, just that
//we'll have to provide second value in the pair different(unique).