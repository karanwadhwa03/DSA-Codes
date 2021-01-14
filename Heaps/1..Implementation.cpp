//Building Heap

#include<bits/stdc++.h>
using namespace std;
void heapify(int A[],int n,int index){
    int largest=index;
    int l=2*index+1;
    int r=2*index+2;

    if(l<n &&A[l]>A[largest])
        largest=l;
    if(r<n && A[r]>A[largest])
        largest=r;

    swap(A[index],A[largest]);

    if(largest!=index)
        heapify(A,n,largest);
}

int main(){
    int A[6]={1,2,88,4,3,5};
    int n=6;
    int start=n/2-1;
    for(int i=start;i>=0;i--)
        heapify(A,n,i);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";



}
