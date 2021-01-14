//find-longest-substring-containing-k-distinct-characters

#include<bits/stdc++.h>
using namespace std;
int main(){

   	string A = "abcbdbdbbdcdabd";
	int k = 2;
	int n = A.length();
  	set<char> window;
    map<char,int> tmap;
    int start=0,end=0;
    int low=0;
    for(int i=0;i<n;i++){
        tmap[A[i]]++;
        window.insert(A[i]);

        while(window.size()>k){
            if(--tmap[A[low]]==0){
                window.erase(A[low]);
            }
            low++;
        }
        if(i-low>end-start){
            start=low;
            end=i;
        }
    }
    cout<<A.substr(start,end-start+1);
}
