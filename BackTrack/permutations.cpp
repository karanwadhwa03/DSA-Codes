#include<bits/stdc++.h>
using namespace std;
void permuate(string s,int l,int r){
if(l==r){
cout<<s<<" ";
return;
}
for(int i=l;i<=r;i++){
swap(s[i],s[l]);
permuate(s,l+1,r);
swap(s[i],s[l]);

}

}
int main(){
string s="ABC";
permuate(s,0,2);
}
