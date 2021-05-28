#include<bits/stdsc++.h>
using namespace std;

int maxSum(int a[],int n){
    int dp[100]={0};

    dp[0]=a[0]>0?a[0]:0;
    int max_so_far = dp[0];

    for(int i=0i<n;i++){
        dp[i] = dp[i-1]+a[i];
        if(dp[i]<0)dp[i]=0;
        max_so_far = max(dp[i],max_so_far);
    }
    return max_so_far;
}

//space efficient:

int maxSumKdane(int a[],int n){

    int cs=0;
    int max_so_far = 0;
    for(int i=0;i<n;i++){
        cs +=a[i];
        if(cs<0)cs=0;
        max_so_far=max(cs,max_so_far);
    }
    return cs;
}




int main(){

}