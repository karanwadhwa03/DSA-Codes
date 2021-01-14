//https://cses.fi/problemset/task/1068/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n>1){
        if(n&1){
            n=n*3+1;
            cout<<n<<" ";
        }
        else{
            n/=2;
            cout<<n<<" ";
            
        }
        
        
    }
    
}