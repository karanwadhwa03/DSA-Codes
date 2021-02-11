#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int A[n];
    int i;
    for(i=0;i<n;i++)
        cin>>A[i];
    int dp[1000001];
    for(i=1;i<=x;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    //cout<<dp[i];
    for(i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=A[j]){
                dp[i]=min(dp[i],1+dp[i-A[j]]);
            }


        }
    }
    if(dp[x]==INT_MAX)
    cout<<"-1";
    else
    cout<<dp[x];

}
