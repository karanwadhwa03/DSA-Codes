//length-of-smallest-subarray-with-sum-greater-number

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n=8;
	int k = 21;
    int len=INT_MAX;
    int low=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        while(sum>k && low<=i){
            len=min(len,i-low);
            sum-=A[low];
            low++;
        }
    }
    cout<<"MINIMUMLENGTH IS "<<len;




}
