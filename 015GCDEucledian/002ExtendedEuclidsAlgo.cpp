//given eqn of the type
//Ax + By = GCD(A,B)
//For given values of A and B find out x and y.
//Reduce the eqn.

//B x1 + (A%B) y1 = GCD(B,A%B)
//by using the result:
// A%B = A - (A/B)*B

//substituting the values and comparing the coefficients:
// X = y1; y = x1 - LB[a/b]*y1
 
 //-----------------------------------------------code----------------------------------------------------

 #include<bits/stdc++.h>

 using namespace std;

 int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int x,y,GCD;
void extendedEuclid(int a, int b)
{
    if(b==0){
        x=1;
        y=0;
        GCD = a;
        return;
    }
    //assumed recursion did its work
    extendedEuclid(b,a%b);

    int cX = y;
    int cY = x - (a/b)*y;

    x= cX;
    y=cY;

}

int main(){

    int a,b;;
    cout<<"Enter the values of a and b; :<<"\n;

    cin>>a>>b;
    
    cout<<gcd(a,b);

    // For the eqn: 18X + 30Y = 6
    extendedEuclid(18,30);
}