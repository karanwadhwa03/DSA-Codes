//https://codeforces.com/problemset/problem/32/B

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i;
    for( i=0;i<(s.length()-1);i++){
        if(s[i]=='-'){
            if(s[i+1]=='-')
            {	cout<<'2';
                i++;
            }
            else
            {
                cout<<"1";
                i++;
            }
            
            
            
        }
        else{
            cout<<"0";
        }
        
        
    }
    //cout<<i;
    if(i!=(s.length()))
        cout<<"0";
    
    
}