//word-break-problem-using-trie

#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    bool isend;
    map<char,Trie*> tmap;
};

Trie* getNode(){
    Trie *Node=new Trie;
    Node->isend=false;
    return Node;

}

void insert(Trie* &head,string s){
    if(head==NULL)
        head=getNode();
    Trie *root=head;
    int n=s.length();
    int i=0;
    while(i<n){
        if(root->tmap.find(s[i])==root->tmap.end())
            root->tmap[s[i]]=getNode();
        root=root->tmap[s[i]];

     i++;
    }

    root->isend=true;
}

bool wordbreak(Trie *head,string s){
    if(head==NULL)return false;
    int n=s.length();
    vector<int> dp(n+1,false);
    dp[0]=true;
    int i=0;
    Trie *curr=head;
    for(i=0;i<n;i++){
        if(dp[i]){
            //cout<<i<<" ";
            curr=head;
            for(int j=i;j<n;j++){
                if(!curr) break;
                curr=curr->tmap[s[j]];

                if(curr && curr->isend)
                    dp[j+1]=true;


            }


        }

    }





    return dp[n];



}

int main(){
    Trie *head=NULL;
    vector<string> dict =
	{
		"this", "th", "is", "famous", "word", "break", "b", "r",
		"e", "a", "k", "br", "bre", "brea", "ak", "prob", "lem"
	};

	// use trie to store dictionary

	for (string const &s: dict) {
		insert(head, s);
	}

    string str = "wordbreakproblem";

    if(wordbreak(head,str))
        cout<<"SUCCESS";
    else
        cout<<"FAILURE";




}
