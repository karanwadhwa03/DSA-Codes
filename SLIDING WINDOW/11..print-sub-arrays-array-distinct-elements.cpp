//print-sub-arrays-array-distinct-elements

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[6] = { 5, 2, 3, 5, 4, 3 };
    int n=6;
    map<int,int> freq;
    int start=0,end=0;
    int low=0;
    for(int i=0;i<n;i++){
        if(freq.find(A[i])==freq.end()|| freq[A[i]]==0){
            freq[A[i]]++;

        }
        else{
            cout<<low<<" "<<i-1<<endl;
            while(A[low]!=A[i]){
                freq[low]--;
                low++;
            }
            low++;
            freq[A[i]]++;
        }



    }
    cout<<low<<" "<<n-1<<endl;


}
