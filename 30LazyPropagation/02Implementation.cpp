//we need an extra array to store the lazy values


void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index)
{
    //resolving the lazy value if it exists:
    if(lazy[index] != 0){
        
        tree[index] += lazy[index];

        //non leaf node
        if(ss!=se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index +1] += lazy[index];
        }
        lazy[index] = 0;
    }

    //base case 
    //no overlap
    if(ss<r || l>se)return;

    //complete overlap
    if(ss>=l && se<=r){
        tree[index] += inc;

        if(ss!=se){
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;            
        }
        return;
    }

    //recursive cas
    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    //updating the tree index:
    tree[index] = min(tree[2*index],tree[2*index +1]);
    return;
}

int queryLazy(int *tree, int ss,int se, int qs,int qe,int index){

    //resolving the lazy value if it exists:
    if(lazy[index] != 0){
        
        tree[index] += lazy[index];

        //non leaf node
        if(ss!=se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index +1] += lazy[index];
        }
        lazy[index] = 0;
    }
    //query logic
    //no overlap
    if(ss>qe || se<qs)
    {
        return INT_MAX:
    }
    //complete overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }

    //partial overlap

    int mid = (ss+se)/2;

    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);

}