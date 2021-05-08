//no of people in a hall so that there's x% chance of 2 people having 
//the birthday on the same day

//complemet of P
//all people have diff bday = 1-x;
//for n=2
// (365 C 1)/365 x (364 C 1)/365 = 99.73%
//for n=3
//99.17%

//at N=23 prob shoots down to less than 50%


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define M 1000000007

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    float x = 1.0;

    int people =0;
    float num =365;
    float denom = 365;
     float p;
     cin>>p;
     if(p == 1.0)
     {
            cout<<"365"<<endl;
            return 0;
     }

     while(x>1-p){

            x=x*(num)/denom;
            num--;
            people++;
            cout<<"People "<<people<<" Prob "<<x<<endl;
     }

}