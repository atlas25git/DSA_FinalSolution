//implicit graphs -2d matrices
//flood fill -> fills colors till any boundary is encountered in all the dirn. as defiined

//this program will replace all the chars within a given range of delimiter boundary to the one asked to fill
#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int R,C;

void printMat(char input[][50]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cout<<input[i][j];
        cout<<endl;
    }
}

void floodFill(char mat[][50],int i,int j, char ch,char color){
    
    if(i<0||j<0||i>=R||j>=C)return;

    if(mat[i][j]!=ch)return;

    mat[i][j]=color;
    for(int k=0;k<4;k++)
    {
        floodFill(mat,i+dx[k],j+dy[k],ch,color);
    }

}

int main(){

    freopen("input.txt","r",stdin);

    // cin>>R>>C;
    R=15,C=50;
    char input[15][50];

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cin>>input[i][j];
    }
    printMat(input);
    floodFill(input,8,13,'.','r');
    cout<<endl;
    printMat(input);

    return 0;
}