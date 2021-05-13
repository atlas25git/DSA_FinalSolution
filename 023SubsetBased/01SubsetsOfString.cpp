//for n elements total no of subsets = 2^(n)
//recursively implement 2 choices for every elements, either to choode it or not
 
#include<bits/stdc++.h>
using namespace std;

void generateSubs(char * in,char* out,int i,int j){
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    out[j] = in[i];
    generateSubs(in,out,i+1,j+1);

    out[j]='\0';
    generateSubs(in,out,i+1,j);
}

int main(){
    char input [] = "abc";
    char output[10];
    generateSubs(input,output,0,0);
}