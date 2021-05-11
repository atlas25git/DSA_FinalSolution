// phi(8) -> No of co prime no's with 8 and are <8
// phi(8)=[1,3,5,7] = 4
// co prime -> gcd(a,b) = 1;

// phi(n) = n*{1 - 1/p1}*{1-1/p2}*{1-1/p3}......{1-1/pk}

// pi -> i'th prime factor of n.

// phi(25) = 25[1-1/5] => 20

//Computing Divisors:
//1.Brute Force
//2. Check till sqrt(N)
//3. Divisors of all nos. from 1 to N;
//--------------------------------------------------------
//Populate the sieve from prime nos, mark all of their multiples if not already with smaller prime
// |2|3|2|5|2|7|2|3| 2| 11| 2| 13| 2|5 
//1 2 3 4 5 6 7 8 9 10  11 12  13 14 15
//For 15 in sieve -> 3, now check at 15/3 ->5
//For 8 -> check at 8->2,now at 8/2, 4->2, 4/2-> 2