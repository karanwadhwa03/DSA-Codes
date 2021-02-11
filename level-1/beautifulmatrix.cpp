//https://codeforces.com/problemset/problem/263/A

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[1000][1000];
    int ii,jj;
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>A[i][j];

        }

    }

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(A[i][j]==1)
            {ii=i; jj=j;
            }

        }
    }
    int ans=0;

    ans=abs(2-ii)+abs(2-jj);
    cout<<ans;


}
