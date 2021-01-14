//find-maximum-sequence-of-continuous-1s-can-formed-replacing-k-zeroes-ones

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[12] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
    int n=12;
	int k = 2;
    int start=0,end=0;
    int low=0;
    int count=0;

    for(int i=0;i<n;i++){
        if(A[i]==0){
            count++;
        }
        while(count>k){
            while(A[low]){
                low++;
            }
            count--;
            low++;
        }
        if(end-start<i-low){
            end=i;
            start=low;
        }

    }
    cout<<" START "<<start<<" END "<<end<<" SIZE "<<" "<<end-start+1;





}
