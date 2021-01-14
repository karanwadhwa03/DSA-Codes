//https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
int required(int A[],int mid,int n){
    int i=1;
    int count=1;
    int j=0;
    while(i<n){
        int sum=A[i]-A[j];
        if(sum>=mid){
            count++;
            j=i;
        }
        
        i++;
    }
    return count;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,b;
        cin>>n>>b;
        int i,A[n];
        
        for(i=0;i<n;i++)
            cin>>A[i];
        int l=INT_MAX;
        for(i=1;i<n;i++)
            l=min(A[i]-A[i-1],l);
        int r=A[n-1]-A[0];
        int mid;
        while(l<r){
             mid=(l+r)/2;
            int req=required(A,mid,n);
            if(req>b){
            l=mid+1;
        	}
        	else{
            r=mid;
        	}
            
            
        }
        
        cout<<l<<" ";
        
        
        
        
    }
    
    
    
    
    
}