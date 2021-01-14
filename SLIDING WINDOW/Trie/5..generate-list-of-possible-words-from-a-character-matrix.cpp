//generate-list-of-possible-words-from-a-character-matrix

#include<bits/stdc++.h>
using namespace std;

#define M 4
#define N 4

int row[8]={1,1,-1,-1,0,0,-1,1};
int col[8]={1,-1,0,-1,1,-1,1,0};

class Trie{
  public:
    bool isend;
    map<char,Trie*> tmap;
};

Trie* getNode(){
    Trie* Node=new Trie;
    Node->isend=false;
    return Node;
}

void insert(Trie* &head,string s){
    if(head==NULL)
        head=getNode();
    Trie* root=head;
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

bool issafe(int i,int j,bool visited[M][N],char board[M][N],char ch){
    return i<M && j<N && visited[i][j]!=true && board[i][j]==ch && i>=0 && j>=0;


}

void Dfs(Trie *root,char board[M][N],int i,int j,string path,bool visited[M][N],unordered_set<string> &res){

    if(root->isend)
        res.insert(path);

   // cout<<path<<" ";

    visited[i][j]=true;
    for(auto it:root->tmap){

        for(int k=0;k<8;k++){
            if(issafe(i+row[k],j+col[k],visited,board,it.first))
                Dfs(it.second,board,i+row[k],j+col[k],path+it.first,visited,res);
        }
    }

    visited[i][j]=false;





}


int main(){

    char board[M][N] = {
					{'M', 'S', 'E', 'F'},
					{'R', 'A', 'T', 'D'},
					{'L', 'O', 'N', 'E'},
					{'K', 'A', 'F', 'B'}
				};

	vector<string> words { "START", "NOTE", "SAND", "STONED" };
    Trie *head=NULL;
    for(auto word:words)
        insert(head,word);

    int i=0;
    int j=0;
    bool visited[M][N];

    unordered_set<string> res;

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            char ch=board[i][j];
            if(head->tmap[ch]){
                string s="";
                s+=ch;
                Dfs(head->tmap[ch],board,i,j,s,visited,res);

            }

        }
    }
    for(auto ans:res)
        cout<<ans<<endl;



}
