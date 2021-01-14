//find-maximum-length-sequence-continuous-ones-sliding-window

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[10] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
    int n=10;
    int start=0,end=0;
    int low=0;
    int count=0;
    int index;
    int last=-1;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count++;
            last=i;
        }
        if(count==2){
            while(A[low]){
                low++;
            }
            count--;
            low++;
        }
        if(end-start<i-low+1){
            end=i;
            start=low;
            index=last;

        }

    }

    cout<<"INDEX"<<index<<endl;
    cout<<"SIZE"<<end-start+1;


}
