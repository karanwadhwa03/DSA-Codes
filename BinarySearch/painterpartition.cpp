#include<bits/stdc++.h>
using namespace std;

int required(int A[],int mid,int n){
    int i=0;
    int count=1;
    int sum=0;
    while(i<n){
        sum+=A[i];
        if(sum>mid){
            count++;
            sum=A[i];
        }
        i++;
    }
    return count;  
}

int main(){
    int n;
    cin>>n;
    int i,A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    int b;
    cin>>b;
    int time;
    cin>>time;
    int sum=0;
    int maxi=INT_MIN;
    for(i=0;i<n;i++){
        sum+=A[i];
        maxi=max(maxi,A[i]);
    }
    if(b==1){
        cout<<sum<<" ";
        return 0;
    }
    if(b>=n){
        cout<<maxi<<" ";
        return 0 ;
    }
    int mid;
    while(sum>maxi){
    	 mid=(sum+maxi)/2;
    	int req=required(A,mid,n);
        if(req>b){
            maxi=mid+1;
        }
        else{
            sum=mid;
        }
    }
    cout<<maxi*time<<" ";
    
    
}