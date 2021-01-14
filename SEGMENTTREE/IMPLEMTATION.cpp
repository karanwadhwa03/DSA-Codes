//Range Min. Query Segment Tree

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int lazy[1000]={0}; 

void UpdateRangeLazy(int tree[],int S,int E,int l,int r,int inc,int index){
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(S!=E){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];   
        }
        lazy[index]=0;
    }
    
    if(S>r || l>E ){
        return ;
    }
    
    if(S>=l && E<=r){
        tree[index]+=inc;
        
        if(S!=E){
            lazy[2*index]=inc;
            lazy[2*index+1]=inc;
        }
        return ;
    }
    int mid=(S+E)/2;
    UpdateRangeLazy(tree,S,mid,l,r,inc,2*index);
    UpdateRangeLazy(tree,mid+1,E,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;   
}

int QueryInLazy(int tree[],int S,int E,int l,int r,int index){
    if(lazy[index]!=0){
        tree[index]+=lazy[index];
        if(S!=E){
            lazy[2*index]=lazy[index];
            lazy[2*index+1]=lazy[index];
            
        }
        lazy[index]=0;
    }
    if(S>l || E<l)
        return INT_MAX;
    
    if(S>=l && E<=r){
        return tree[index];
    }
    
    int mid=(S+E)/2;
    QueryInLazy(tree,S,mid,l,r,2*index);
    QueryInLazy(tree,mid+1,E,l,r,2*index+1);
    return tree[index]=min(tree[2*index],tree[2*index+1]);
    
    
}


void buildTree(int A[],int tree[],int start,int end,int index){
    if(start==end){
        tree[index]=A[start];
        return;
    }
    
    int mid=start+(end-start)/2;
    buildTree(A,tree,start,mid,2*index);
    buildTree(A,tree,mid+1,end,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;
    
}

int query(int tree[],int S,int E,int l ,int r,int index){
    //Fully Overlap
    if(l<=S && r>=E){
        return tree[index];
    }
    
    if(r<S || l>E){
        return INT_MAX;
    }
    int mid=(S+E)/2;
    int left=query(tree,S,mid,l,r,2*index);
    int right=query(tree,mid+1,E,l,r,2*index+1);
    tree[index]=min(left,right);
    return tree[index];
        
}

void UpdateOnIndex(int tree[],int S,int E,int i,int inc,int index){
    if(i>E || i<S){
        return ;
    }
    if(S==E){
        tree[index]+=inc;
        return;
    }
	
    int mid=(S+E)/2;
    UpdateOnIndex(tree,S,mid,i,inc,2*index);
    UpdateOnIndex(tree,mid+1,E,i,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
       
}

void UpdateOnRange(int tree[],int S,int E,int l,int r,int inc,int index){
    if(r<S || l>E){
        return;
    }
    if(S==E)
    {
        tree[index]+=inc;
        return;
    }
    
    int mid=(S+E)/2;
    UpdateOnRange(tree,S,mid,l,r,inc,2*index);
    UpdateOnRange(tree,mid+1,E,l,r,inc,2*index+1);
 	tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
       
}


int main()
{
    int A[]={1,3,2,-5,6,4};
    int n=6;
    int tree[4*n+1]={0};
    buildTree(A,tree,0,n-1,1);
    
    //int l,r;
    //cin>>l>>r;
    //cout<<query(tree,0,n-1,l,r,1);
    
    //int i,inc;
    //cin>>i>>inc;
    //UpdateOnIndex(tree,0,n-1,i,inc,1);
    //
    //int l,r;
	//cin>>l>>r;
	//cout<<query(tree,0,n-1,l,r,1);
    
    int l,r,inc;
    cin>>l>>r>>inc;
    UpdateRangeLazy(tree,0,n-1,l,r,inc,1);
    
    int q1,q2;
    cin>>q1>>q2;
    cout<<QueryInLazy(tree,0,n-1,q1,q2,1);
    
	
    
        
}