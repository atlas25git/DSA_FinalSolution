//d1,d2,d3....dn : N<=10k
//breaking the problem into smaller subproblems
//x{------}
//     s       s+x=S
//(x+s)%D=0
//extended to 
//(x%D + s%D)%D = 0
//x%D + s%D = mD
//=> s%D = mD - x%D 
//adding D to both the sides and taking modulo
//s%D = (D - X%D)%D
//=> s=D-x%D
//similarly subsequent parts can be broken down
//dp(pos,d) = count of numbers such that we are yet to fix digits in places [pos-(N-1)] and S%D=d
//base case 
//dp(0,0) -> after fixing all the digits from 0 to N-1 and after the fix S%D==0
//dp(pos,d) = summation(x:0,9)dp(pos+1,D+d-x%D)
//this is for the easier version of the problem, where we're looking from 00000.. to 99999....
//managing not exceeding K
 