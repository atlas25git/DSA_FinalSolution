//all possible paths from source to destination
#include<bits/stdc++.h>
using namespace std;

int cnt =0;


bool ratInMaze(char maze[10][10],int soln[][10], int i,int j, int m, int n){
    
   

    if(i==m && j==n){
        soln[m][n]=1;
        cnt++;
        for(int i1=0;i1<=m;i1++){
            for(int j1=0;j1<=n;j1++)
            {
                cout<<soln[i1][j1]<<" ";
            }
            cout<<"\n";
           
        }
         cout<<"Path->"<<cnt<<"\n";

        return true;
    }
    if(i>m || j>n) return false;
    if(maze[i][j]=='X')return false;

    //assuming soln exists through the curr maize
    soln[i][j]=1;

    bool rightSuccess = ratInMaze(maze,soln,i,j+1,m,n);
    bool downSuccess = ratInMaze(maze,soln,i+1,j,m,n);

    soln[i][j] = 0;

    if(rightSuccess || downSuccess)return true;
    else return false;
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","1",stdout);

    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0x00",
    };
    int soln[10][10] = {0};

    bool exist = ratInMaze(maze,soln,0,0,3,3);
    if(!exist)cout<<"Path doesn't exist";
}
