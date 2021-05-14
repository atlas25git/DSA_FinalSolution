#include<bits/stdc++.h>
#include<bitset>

using namespace std;

//Optimizing isSafe fn to work in O(1) time
//sum of indices along a diagonal is same for all the cells on it
//therefore this could be leveraged to be used in some sort of hashing
//same could be employed for columns
//and also for the other diagonals
//r+c, r-c diagonal property

bitset<30> col,d1,d2;
//reduces time complexity to 1/n of orginal\.
void solve(int r,int n,int &ans,int board[][20]){
    if(r==n){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout<<"| Q |";
                }
                else cout<<"| _ |";
            }
            cout<<endl;
        }
        cout<<endl;

        ans++;
        return;
        }

    for(int c=0;c<n;c++){
        if(!col[c] && !d1[r-c+n-1] && ! d2[r+c]){
            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] =1;
            solve(r+1,n,ans,board);
            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] =0;
        }
    }
}



int main(){
    int n;
    cin>>n;
    int board[20][20] = {0};
    //solveNQueen(board,0,n);
    int ans =0;
    solve(0,n,ans,board);
    cout<<ans<<endl;
}