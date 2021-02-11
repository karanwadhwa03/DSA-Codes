//TRIE IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
  	bool isend;
  	map<char,Trie *>tmap;
};

Trie * getNode(){
   	Trie *node = new Trie;
    node->isend=false;
    return node;
}

void insert(Trie *&head,string s){

    if(head==NULL)
        head=getNode();
    Trie *root=head;
    int n=s.size();
    int i=0;
    while(i<n){

        if(root->tmap.find(s[i])==root->tmap.end())
        	root->tmap[s[i]]=getNode();

        root=root->tmap[s[i]];
        i++;
    }
    root->isend=true;
}

int search(Trie *head,string s){
    
    Trie *root=head;
    if(root==NULL)return 0;
    int i=0;
    int n=s.size();
    while(i<n){
        root=root->tmap[s[i]];
        if(root==NULL)return 0;

        i++;
    }
    return root->isend?1:0;
}

int main(){
    Trie *head=NULL;
    insert(head,"hello");
    cout<<search(head,"helloW")<<endl;
    cout<<search(head,"hello")<<endl;
    cout<<search(head,"hell")<<endl;




}
