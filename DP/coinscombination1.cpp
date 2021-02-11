#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
        sort(A,A+n);
    int dp[1000000]={0};
    for(int i=0;i<n;i++)
        dp[A[i]]=1;
   	for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i<A[j])
            break;
            dp[i]=dp[i]+dp[i-A[j]];

        }
    }

    cout<<dp[x];



}
