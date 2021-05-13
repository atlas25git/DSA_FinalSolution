#include<bits/stdc++.h>
using namespace std;

void replacePi(char a[], int &i){
    if(a[i] == '\0' or a[i+1] == '\0')return;

    if(a[i]=='p' && a[i+1]=='i'){
        
        int j=i+2;
        while(a[j] !='\0'){j++;}
        //shifting
        while(j>=i+2){
            a[j+2] = a[j];//j+2 coz that's the effective no. of shift places/
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        i+=4;
        replacePi(a,i);


    }
    else{
        i++;
        replacePi(a,i);
    }
    return;

}


int main(){
    char a[1000];
    cin>>a;
    int i=0;
    replacePi(a,i);
    cout<<a<<endl;

}