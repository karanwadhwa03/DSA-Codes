//https://www.geeksforgeeks.org/window-sliding-technique/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[9] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int n=9;
    int k = 4;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=A[i];
    }
    int ans=sum;
    for(int i=k;i<n;i++){
        sum=sum+A[i]-A[i-k];
        ans=max(sum,ans);
    }
    cout<<ans<<" ";



}
