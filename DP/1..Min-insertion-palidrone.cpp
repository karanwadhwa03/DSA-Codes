//Min-insertion-palidrone

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(1000,vector<int>(1000,-1));



int req(string A,int l,int r){
    if(l>=r)
        return 0;

    if(dp[l][r]!=-1)
        return dp[l][r];

    if(A[l]==A[r])
        return dp[l][r]= req(A,l+1,r-1);

    else{
        return dp[l][r]=min(req(A,l+1,r),req(A,l,r-1))+1;

    }
}

int main(){
    string A="geeks";
    int n=A.length();
    cout<<req(A,0,n-1);



}
