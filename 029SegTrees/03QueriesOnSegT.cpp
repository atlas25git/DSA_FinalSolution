//overlaps->
//complete->return ans at index
//partial-> 2 sub calls made falling on the lines of other 2 cases
//no ->return infinity
#include<bits/stdc++.h>
using namespace std;


int query(int* tree,int ss,int se, int qs,int qe,int index){

    //complete overlap
    if(qs<=ss && se<=qe) return tree[index];

    //no overlap
    if(qe<ss || qs>se)return INT_MAX;

    int mid = (ss+se)/2;
    int l=query(tree,ss,mid,qs,qe,2*index);
    int r=query(tree,mid+1,se,qs,qe,2*index+1);
    return mid(left,right); 
}