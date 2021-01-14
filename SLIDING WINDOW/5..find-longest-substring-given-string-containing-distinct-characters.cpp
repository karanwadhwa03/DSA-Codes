//find-longest-substring-given-string-containing-distinct-characters

#include<bits/stdc++.h>
using namespace std;
int main(){
    string A = "abbcdafeegh";
	int n = A.length();
    map<char,bool> tmap;
    int start=0,end=0;
    int low=0;
    for(int i=0;i<n;i++){
        if(tmap[A[i]]==false){
            tmap[A[i]]=true;

        }
        else{
            while(A[low]!=A[i]){
                tmap[A[low]]=false;
                low++;
            }
            low++;
            tmap[A[i]]=true;
        }
        if(end-start<i-low){
            start=low;
            end=i;
        }
    }
    cout<<A.substr(start,end-start+1)<<endl;
    cout<<end-start+1<<" ";





}
