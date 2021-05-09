//LR is a fn in which each term is linear comb of previous terms
// rec->2^n exponential
// dp ->O(n)
// matrixExponentiation -> k^3 logN
//k=2 in fib

//Steps
//1. Det K no of terms a term at i depends on
//2. find first k terms of seq.
//3.Transformation matrix, discern!
//4. Ti x Fi = Fi+1
//5. Fn = Tn-1 x F1

//finding transformation matrix


//given recurrence: f(i) = 1f(i-1) + 2f(i-2) +0.f(i-3) + 4f(i-4);
//1. Fi vector = It'll have all the terms without their coefficients
// fi  --------     
//     |f(i-4)|
//     |f(i-3)|
//     |f(i-2)|
//     |f(i-1)|
//     --------
//fi+1 will be the same matrix as fi just i+1 in each i's place
//Now transformation matrix should be such that it could delete all the terms
//starting from f(i-4), such that the top of Fi contains f(i-3) 
//since the last row of Fi+1 will cotain fi, transformational matrix's 
//row should be like: coefficient of the  given equation of fi.