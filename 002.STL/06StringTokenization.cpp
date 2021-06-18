#include<iostream>
#include<cstring>

using namespace std;

//char *strtok(char *s, char* delimiter)
//returns a token on each subsequent call
//string should be passed only at the first call
//on subsequent call pass NULL, to persist on the string used earlier

int main()
{
    char s[100] = "Neon Graves don't start a cult";
    char *ptr = strtok(s," ");

    cout<<ptr<<endl;

    for(int i =0;i<5;i++){
        ptr = strtok(NULL," ");
        cout<<i+1<<" "<<ptr<<endl;
    }    
}