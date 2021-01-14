#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
string res;
void subsets(string s,int l,int r){
  ans.push_back(res);
  for(int i=l;i<=r;i++){
    res.push_back(s[i]);
    subsets(s,i+1,r);
    res.pop_back();

  }





}


int main(){
  string s="ABC";
  subsets(s,0,2);
  for(auto i: ans)
  cout<<i<<" ";
}
