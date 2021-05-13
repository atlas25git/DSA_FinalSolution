#include<bits/stdc++.h>
using namespace std;

int stringToInt(char* a,int n)
{
    if(n==0)return 0;

    int digit = a[n-1]-'0';
    return stringToInt(a,n-1)*10+digit;
}

int main(){
    char a[]= "1234";
    int no=stringToInt(a,4);
    no++;
    cout<<no;
}