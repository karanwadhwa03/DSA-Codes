//stickler-thief

#include<bits/stdc++.h>
using namespace std;

int main(){

    int A[5]={1,2,3,1000,5};
    int n=5;
    vector<int> dp(1000,-1);
    dp[0]=A[0];

    dp[1]=max(A[0],A[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+A[i]);

    }
    cout<<dp[n-1];






}
