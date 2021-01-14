//https://gist.github.com/ankeshanand/01c7961abf637dba7249
//https://www.spoj.com/problems/GSS1/
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <climits>
#include <ctime>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <iomanip>
#include <cstdarg>
#include <utility> //std::pair
#include <cassert>

using namespace std;

// Input macros
#define s(n)    scanf("%d",&n)
#define sc(n)   scanf("%c",&n)
#define sl(n)   scanf("%lld",&n)
#define sf(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)

//Pair macros
#define mp make_pair // useful for working with pairs
#define fi first
#define se second

#define ll long long //data types used often, but you don't want to type them time by time_t

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back

#ifdef DEBUG
     #define debug(args...)            {cerr << #args << ": ";dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

vector<long long int> A;

typedef struct node{
    ll int sum;
    ll int best;
    ll int best_left;
    ll int best_right;
    node(ll int a, ll int b, ll int c, ll int d)
    {
        sum = a;
        best = b;
        best_left = c;
        best_right = d;
    }
}node;

vector<node> tree(1000002, node(0,0,0,0));
void build_tree(int idx, int ss, int se)
{
    if(ss > se)
        return;
    if(ss == se){
        // leaf node
        tree[idx] =  node(A[ss],A[ss],A[ss],A[ss]);
        return;
    }
    build_tree(idx*2+1, ss, (ss+se)/2);
    build_tree(idx*2+2, (ss+se)/2 + 1, se);

    tree[idx].sum = tree[idx*2+1].sum + tree[idx*2+2].sum;
    tree[idx].best_left = max(tree[idx*2+1].best_left, tree[idx*2+1].sum + tree[idx*2+2].best_left);
    tree[idx].best_right = max(tree[idx*2+2].best_right, tree[idx*2+1].best_right + tree[idx*2+2].sum);
    tree[idx].best = max(max(max(tree[idx].sum,tree[idx*2+1].best_right + tree[idx*2+2].best_left), tree[idx*2+1].best), tree[idx*2+2].best);
    tree[idx].best = max(tree[idx].best, tree[idx].best_left);
    tree[idx].best = max(tree[idx].best, tree[idx].best_right);
}

node query_tree(int idx, int ss, int se, int qs, int qe)
{
    if(ss > se || ss > qe || se < qs)
        return node(INT_MIN,INT_MIN,INT_MIN,INT_MIN);

    if(ss >= qs && se <= qe)
        return tree[idx];

    node q1 = query_tree(idx*2+1, ss, (ss+se)/2, qs, qe);
    node q2 = query_tree(idx*2+2, (ss+se)/2+1, se, qs, qe);

    node q(0,0,0,0);
    q.sum = q1.sum + q2.sum;
    q.best_left = max(q1.best_left, q1.sum + q2.best_left);
    q.best_right = max(q2.best_right, q1.best_right + q2.sum);
    q.best = max(q1.best, q2.best);
    q.best = max(q.best, q1.best_right + q2.best_left);
    q.best = max(q.best, q1.sum + q2.sum);
    q.best = max(q.best, q.best_left);
    q.best = max(q.best, q.best_right);
    return q;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        long long int t;
        scanf("%lld",&t);
        A.push_back(t);
    }
    build_tree(0, 0, n-1);
    
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int xi,yi;
        s(xi);
        s(yi);
        xi--;
        yi--;
        printf("%lld",query_tree(0, 0, n-1, xi, yi).best);
        if(i != m-1)
            printf("\n");
    }
}