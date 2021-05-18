//prefix sums, alongwith incoming updates
//easy to code, and memory optimized n compared to 4n
//we build a BIT array
//value represented by every node: 
//BIT[i] -> stores the ans of the range [l,r]
//l = i - 2^r +1; //r being the right most set bit's position
//r = i
//bit(2) = [1,2] ->ans
//for every odd indices since the right most set bit would be at 0,
//hence the formula would reduce to l=i, and since r=1, every odd index
//would store the value of the single element
//bit(4) -> [1,4];
//for all powOf2 indices -> answer would be in the range [1,i]
