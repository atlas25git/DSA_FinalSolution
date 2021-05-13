#include<bits/stdc++.h>

using namespace std;

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpellings(int n){
    if(n==0)return;

    //we assume 204 have got thier spellings printed, we 
    //just need to handle the remaining part

    printSpellings(n/10);

    cout<<words[n%10]<<" ";
    return;
}

int main(){
    printSpellings(2048);
}