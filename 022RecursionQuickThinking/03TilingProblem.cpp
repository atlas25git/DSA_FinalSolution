//Given a wall of size 4xN and tiles of 1,4 and 4,1
//give total no of ways wall could be form

//solution approach
//since the wall length is n, we say total no of ways to build the wall is f(n)
//now if the first brick is vertical = f(n-1)//left
//horizontal = f(n-4)
// => f(n) = f(n-1) + f(n-4);//rec case
//=>base case=> if(n<=3)return 1;

#include<bits/stdc++.h>
using namespace std;



int main(){

}