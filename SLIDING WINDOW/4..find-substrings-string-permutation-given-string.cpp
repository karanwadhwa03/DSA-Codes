//find-substrings-string-permutation-given-string

#include<bits/stdc++.h>
using namespace std;
int main(){
    string X = "XYYZXZYZXXYZ";
	string Y = "XYZ";
    multiset<char> window;
    multiset<char> req;
    int n=X.length();
    int m=Y.length();
    for(int i=0;i<m;i++)
        req.insert(Y[i]);

    for(int i=0;i<m;i++){
        window.insert(X[i]);
    }

    if(req==window)
        cout<<"FIND AT 0"<<endl;
    for(int i=m;i<n;i++){
        auto it=window.find(X[i-m]);
        if(it!=window.end())
            window.erase(it);
        window.insert(X[i]);
        if(req==window)
            cout<<"FIND AT "<<i-m+1<<endl;

    }



}
