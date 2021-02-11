//lexicographic-sorting-given-set-of-keys
//also done by sorting
//for duplicate word a char array shoul be used



#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
    string str;
    map <char,Trie*>tmap;

};

Trie* getNode(){
    Trie *Node=new Trie;
    Node->str="";
    return Node;
}

void insert(Trie *&head,string s){

    if(head==NULL)
        head=getNode();
    Trie * root=head;
    int i=0;
    int n=s.size();
    while(i<n){
        if(root->tmap.find(s[i])==root->tmap.end())
            root->tmap[s[i]]=getNode();
        root=root->tmap[s[i]];

        i++;
    }
    root->str=s;

}

void preorder(Trie *head){
    if(head==NULL)
        return ;

    for(auto it:head->tmap){

        if(it.second->str.length()>0)
            cout<<it.second->str<<endl;

        preorder(it.second);

    }


}


int main(){

    string dict[] =
	{
		"lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
		"be", "accomplished", "with", "a", "simple", "trie", "based",
		"algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
		"output", "all", "keys", "in", "the", "trie", "by", "means", "of",
		"preorder", "traversal", "which", "results", "in", "output", "that",
		"is", "in", "lexicographically", "increasing", "order", "preorder",
		"traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
	};
	Trie * head=NULL;
	// insert all keys of dictionary into trie
	for (string word: dict) {
		insert(head, word);
	}

    preorder(head);



}
