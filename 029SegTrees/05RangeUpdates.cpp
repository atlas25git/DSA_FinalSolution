
#include<bits/stdc++.h>

using namespace std;

//operation to be performed over a range of indices
//in case of a complete overlap all the nodes till the very leaf node need be updated
//could be ignored for the no overlap case


void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index)
{
   if(l>se || r<ss)return;
   if(se==ee)
   {
       tree[index] += inc;
       return;
   }
   int mid = (ss+se)/2;
   updateRange(tree,ss,mid,l,r,inc,2*index);
   updateRange(tree,mid+1,se,l,r,inc,2*index+1);
   tree[index] = min(tree[2*index],tree[2*index+1]);
   return;
}   