Counting no of bsts from n no of nodes given [1,n].

for the ith node:
1,2,3,4,5,....,i-1, i ,i+1,...+,N

for total bsts with i as root=>
f(i) = f(i-1) + f(N-i)

let's say we can make x trees from i-1,i.e, f(i-1) = x,f(N-1) = y;

Then the total no of trees:
summationOfAllI(X(C)1*1*Y(C)1);

f(0)=1; Null tree is also a tree
f(1)=1;
f(2)=f(0)*f(1) + f(1)*f(0);

it is also given by catalan as series:
Nth term of it = =2n(C)n/n+1; -> gives ans in one iteration summation not required/
Through this we can eliminate the need of dp array required.

1) unlabeled Binary Trees = same as BST
2) Binary tree-> n! 2n(C)n/n+1;