//count-distinct-elements-every-sub-array-size-k-array

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> A = { 1, 1, 2, 1, 3 };
	int k = 3;
    int n=A.size();
    //cout<<n<<" ";
    map<int,int> tmap;
    int count=0;
    for(int i=0;i<k;i++){
        if(tmap.find(A[i])== tmap.end() || tmap[A[i]]==0 ){
        	tmap[A[i]]++;
            count++;
        }
        else{
            tmap[A[i]]++;

        }
    }
    cout<<count<<" ";
    for(int i=k;i<n;i++){
        if(tmap[A[i-k]]==1){
            count--;
        }
        tmap[A[i-k]]--;
        if(tmap.find(A[i])== tmap.end() || tmap[A[i]]==0 ){
        	tmap[A[i]]++;
            count++;
        }
        else{
            tmap[A[i]]++;

        }
        cout<<count<<" ";


    }





}
