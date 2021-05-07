#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <

    typename Key,
    typename Mapped,
    typename Cmp_Fn = std::less<key>,
    typename Tag = rb_tree_tag,

    template <

        typename Const_Node_Iterator,
            typename Const_Node_Iterator,
            typenmame Node_Iterator,
            typename Cmp_Fn_,
            typename Allocator,    
            >
            class Node_Update = null_node_update,

            typename Allocator = std::allocator<char>

        >

class tree;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;


setting on window: 
rename orrectly hash_standard...imp.hpp(00000644 added)

works like a set
both in O(logN), whereas bS takes NlogN;
find_by_order: kth largest
order_of_key:  return np. of elements strictly less than k

Both the fn are vice versa of each other, index in the DS provides fo rank, and this is used both ways.
If key not present, then would return nos smaller than it.