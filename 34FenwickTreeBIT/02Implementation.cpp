//for a change at index i we update all the indices of pow2<Range of array
//coz it contains the cumulative array 
//even for he odd indices we'll update those indices which are compleely in the form of
//pow of 2
//update - O(lohN)
//build O(NlogN)
//other even nos which baren't exactly comprised of 2s, store the sum in the range
//of [last index with all 2s,curr index]

//query->
//query for i -> sum of arr elements from index 1 to i
//query(l,r) -> query(r) - query(l-1)
//simply remove last set bit