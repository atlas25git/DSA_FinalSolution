//max subarray sum in the given query range
//for the given query ans could lie in wither of the halves
//or might be given by inclusion from both the parts

#include<bits/stdc++.h>
using namespace std;

long long int arr[50005]; //input array
struct Tree
{
    long long int prefix, suffix, total, best;
};

Tree tree[200005];
void build_tree(long long int node, long long int a, long long int b)
{
    if (a == b)
        { //leaf node
        tree[node].prefix = arr[a]; // prefix sum
        tree[node].suffix = arr[a]; // suffix sum
        tree[node].total = arr[a]; // total sum
        tree[node].best = arr[a]; // best sum
    return;
    }
  
    int mid = (a + b) >> 1;
    build_tree(node * 2, a, mid);
    build_tree(node * 2 + 1, mid + 1, b);

    tree[node].prefix = max(tree[node * 2].prefix, tree[node*2].total + tree[node *2 + 1].prefix); //prefix sum

    tree[node].suffix = max(tree[node * 2 + 1].suffix, 
                            tree[node * 2].suffix + tree[node * 2 + 1].total); //suffix sum

    tree[node].total = tree[node * 2].total + tree[node *2 + 1].total; //total sum

    tree[node].best = max(tree[node * 2].suffix + tree[node * 2 + 1].prefix,
                            max(tree[node * 2].best, tree[node *2 + 1].best)); //best sum
}

Tree query_tree(long long int node, long long int a, long long int b, long long int i, long long int j)
{
    Tree t;
    if (a > b || a > j || b < i)
    {
        t.prefix = t.suffix = t.best = INT_MIN ;
        t.total = 0;
        return t;
    }
    
    if (a >= i && b <= j)
    {
        return tree[node];
    }
    long long int mid = (a + b) >> 1;
    Tree q1 = query_tree(node * 2, a, mid, i, j);
    Tree q2 = query_tree(node * 2 + 1, mid + 1, b, i, j);

    t.prefix = max(q1.prefix, q1.total + q2.prefix);
    t.suffix = max(q2.suffix, q1.suffix + q2.total);
    t.total = q1.total + q2.total;
    t.best = max(q1.suffix + q2.prefix, max(q1.best, q2.best));
    return t;
}
