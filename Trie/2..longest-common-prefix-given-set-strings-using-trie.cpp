//longest-common-prefix-given-set-strings-using-trie

#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    bool isend;
    map<char,Trie*> tmap;
};

Trie * getNode(){
    Trie *node =new Trie;
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

string LCP(Trie *head){
    string ans="";
    Trie *curr=head;
    while(curr && curr->isend!=true && (curr->tmap.size()==1)){
        auto it=curr->tmap.begin();
        char ch=it->first;
        ans+=ch;
        curr=it->second;
    }
    return ans;


}




int main()
{
    string dict[] =
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codependence", "codependency", "codependent",
		"codependents", "codes", "codesign", "codesigned", "codeveloped",
		"codeveloper", "codex", "codify", "codiscovered", "codrive"
	};

	Trie *head=NULL;
	int n = sizeof(dict)/sizeof(dict[0]);
    for(int i=0;i<n;i++)
        insert(head,dict[i]);

    cout<<LCP(head);





}
