//concept of expectation of values is used here
//it's basically the avg of predicted values over the number of total trials
//Contribution technique::
//since expected value is a sum of trials over the operations
// summation(Xi)/N-> therefore here we multiply the contribution of each element using it's fraction of occurrence
//{f*1 + 2*f2 + 3*f3... +6*f6}/N
//where fi denotes fractioion of experiments in which our dice shows an i.
//=> 1/6 + 2/6 + 3/6 + 4/6 + 5/6 +6/6 =3.5
//experiment : rolling a dice till we get a 6
//rand = no of times the dice is rolled
//E(x) : expected no of times we'd be rolling the dice
//= {fractions when we get expected value in one operation}*1 -> 1/6*1
//= {fractions when we get expected value in two operations}*2 -> *5/6*1/6*1
//= {fractions when we get expected value in three operations}*3 -> 5/6*5/6*1/6*1
//.
//.
//.
// summation of { (5/6)^(i-1) * 1/6 *i } over i=1 to inf. = 6

//************************************soultion***************************************************************************************
//For the given problem lets say we've a state A with the given connfiguration of states of dishes
//and we tend to reach to state E whit required configuration {0,0,0,0.....,0}
//Lets say we know the probabillities of reachinfg states S1,S2,S3... from A being P1,P2,P3...
//these operations would be 1 in count
//now lets say expected operations required to reach from  these S states to E is known then the no of operations
//require to reach from state A to E will be
//1+ P1*s1 + P2*s2 + P3*s3 .... Pn*sn;

//Observation: Oredering of the dishes do no matter
//ans{2,2,1} == ans{1,2,2}
//what matter is the dishes witht their types of categories
//lets say we've a state represented by variables
// O->no of dishes with 0 sushis
// x->no of dishes with 1 sushis
// y->no of dishes with 2 sushis
// z->no of dishes with 3 sushis

// so our state given by {O,x,y,z} depends upon:
// Let the sushi be eaten from (sushi eaten from the intiial dish would be reduced to the consecutive -1 state) 
// x -> {0+1,x-1,y,z}
// y -> {0,x+1,y-1,z}
// z -> {0,x,y+1,z-1}
//O=N-x-y-z;

//therefore our recurrence:
//dp(x,y,z) -> exp no of operations to reach the state {0,0,0}
//dp(x,y,z) = 1 + p0*dp(x,y,z) + px*dp(x-1,y,z) + py*dp(x+1,y-1,z) + pz*dp(x,y+1,z-1); 
//since our recurrence is currently dependent on itself rearranging the  equation:
//dp(x,y,z) = (1 + px*dp(x-1,y,z) + py*dp(x+1,y-1,z) + pz*dp(x,y+1,z-1))/(1-p0);

//Base Cases:
//dp(0,0,0)=0;
//minimizing division operations
// Px = x/N, P0 = (N-x-y-z)/N
//(1-p0) = (x+y+z)/N
//therefore the final equation : 
//dp(x,y,z) = {N + x*dp(x-1,y,z) + y*dp(x+1,y-1,z) z*dp(x,y+1,z-1)}/(c+y+z)


//code

#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];

double solve(int x,int y,int z,int& n)
{
    if(x<0 || y<0 || z<0)return 9999;
    if(x==0 && y==0 && z==0)return 0;

    if(dp[x][y][z]>-0.9)return dp[x][y][z];

    double exp = n + x*solve(x-1,y,z,n) + y*solve(x+1,y-1,z,n) + z*solve(x,y+1,z-1,n);

    return dp[x][y][z] = exp/(x+y+z);

}


int main()
{
    int n,x;
    cin>>n;
    memset(dp,-1,sizeof dp);
    int one =0,two=0,three=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)one++;
        else if(x==2)two++;
        else three++;
    }
    //cout<<one<<" "<<two<<" "<<three<<endl;
    cout<<fixed<<setprecision(10)<<solve(one,two,three,n);
}