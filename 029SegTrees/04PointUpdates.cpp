
#include<bits/stdc++.h>

using namespace std;

//here we discuss about point updates where we deal with updating indices
//bottom up paradigm and might be the case that all the nodes on the path get updated
//complexity ->bt->O(n) ->q&u ->O9logN)

void updateNode(int *tree,int ss,int se,int i,int increment,int index)
{
    if(i>se || i<ss)return;
    if(ss==se)
    {
        tree[index] += increment;
        return;        
    }
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}   