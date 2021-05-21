//array implementation
//each element intially -1->denotes singleton set
//to merge we set one of the elements as parent of other
//and we set leaders for each sets

int find(int i){
    if(parent[i]==-1)return i;
    return find(parent[i]);
}

void union(a,b){
    s1 = find(a);
    s2 = find(b);
    if(s1!=s2)parent[s2]=s1;
}

//both O(n)