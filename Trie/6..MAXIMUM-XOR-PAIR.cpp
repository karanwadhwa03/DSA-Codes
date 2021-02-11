//MAXIMUM-XOR-PAIR
//https://www.youtube.com/watch?v=jCu-Pd0IjIA

#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
    Trie* left;
    Trie* right;

};

Trie* getNode(){
    Trie * Node=new Trie;
    Node->left=Node->right=NULL;
    return Node;
}

void insert(Trie* &head,int n){
    if(head==NULL)
        head=getNode();
    Trie* temp=head;
    for(int i=31;i>=0;i--){
        int tempValue=(n>>i)&1;
        if(tempValue==1){
            if(temp->right==NULL)
                temp->right=getNode();
            temp=temp->right;
        }
        else{
            if(temp->left==NULL)
                temp->left=getNode();
            temp=temp->left;
        }

    }
}

int findmaxXOR(Trie *head,int A[],int n){
    //if(!head)return -1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
       	int value=A[i];
        int currValue=0;
        Trie *curr=head;
        for(int j=31;j>=0;j--){
            int b=(value>>j)&1;
            if(b==1){
                if(curr->left){
                    currValue+=pow(2,j);
                    curr=curr->left;
                }
                else
                    curr=curr->right;
            }
            else{
                if(curr->right){
                    currValue+=pow(2,j);
                    curr=curr->right;
                }
                else
                    curr=curr->left;
            }
        }
        ans=max(ans,currValue);
    }
    //cout<<ans<<"k ";
   return ans;


}


int main(){
    int arr[6]={1,2,3,4,10,5};
    Trie *head=NULL;
    int n=6;
    for(int i=0;i<n;i++)
        insert(head,arr[i]);
    //cout<<"K";
    cout<<findmaxXOR(head,arr,n);



}
