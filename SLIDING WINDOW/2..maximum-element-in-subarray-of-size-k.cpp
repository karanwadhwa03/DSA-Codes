// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/?ref=rp

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[7] = { 12, 1, 78, 90, 57, 89, 56 };
    int n=7;
    int k = 3;
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && A[i]>=A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<A[dq.front()]<<" ";
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && A[dq.back()]<=A[i])
            dq.pop_back();
        dq.push_back(i);

        cout<<A[dq.front()]<<" ";
    }



}
