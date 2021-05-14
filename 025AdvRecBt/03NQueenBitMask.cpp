 #include<bits/stdc++.h>
 using namespace std;

  int n;
  int ans=0, DONE;

  void solve(int rowMask,int ld, int rd){
      if(rowMask == DONE){ans++; return;}

      int safe = DONE & (~(rowMask | ld | rd));
      while(safe){
          int p = safe & (-safe);
          safe = safe-p;// p cold be used to discern the pos of board as logP + 1//row wuld be i and increase it for every subsequent call
          solve(rowMask | p, (ld |p) << 1, (rd | p)>>1);
      }
  }

  int main(){
      cin>>n;
      DONE = ((1<<n)-1);
      solve(0,0,0);
      cout<<ans<<endl;
  }