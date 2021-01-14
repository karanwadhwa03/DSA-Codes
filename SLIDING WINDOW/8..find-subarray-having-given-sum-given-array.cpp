//find-subarray-having-given-sum-given-array


#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[10] = { 2, 6, 0, 9, 7, 3, 1, 4, 1, 10 };
	int sum = 15;
    int n=10;
    int req=0;
    int low=0;
    for(int i=0;i<n;i++){

        req+=A[i];
        if(req==sum)
        {
            cout<<"FOUND    "<<low<<"  "<<i<<endl;
            break;
        }
        while(req>sum){
            req-=A[low++];

        }
        if(req==sum){
            cout<<"FOUND    "<<low<<"  "<<i<<endl;
            break;
        }
    }





}
