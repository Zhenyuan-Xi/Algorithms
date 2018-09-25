/*
There is an apple tree outside of kaka's house. Every autumn, a lot of apples will grow in the tree. 
Kaka likes apple very much, so he has been carefully nurturing the big apple tree.
The tree has N forks which are connected by branches. Kaka numbers the forks by 1 to N and the root is always numbered by 1. 
Apples will grow on the forks and two apple won't grow on the same fork. 
kaka wants to know how many apples are there in a sub-tree, for his study of the produce ability of the apple tree.
The trouble is that a new apple may grow on an empty fork some time and kaka may pick an apple from the tree for his dessert. 
Can you help kaka?

Input
The first line contains an integer N (N ≤ 100,000) , which is the number of the forks in the tree.
The following N - 1 lines each contain two integers u and v, which means fork u and fork v are connected by a branch.
The next line contains an integer M (M ≤ 100,000).
The following M lines each contain a message which is either
"C x" which means the existence of the apple on fork x has been changed. i.e. if there is an apple on the fork, then Kaka pick it; otherwise a new apple has grown on the empty fork.
or
"Q x" which means an inquiry for the number of apples in the sub-tree above the fork x, including the apple (if exists) on the fork x
Note the tree is full of apples at the beginning
Output
For every inquiry, output the correspond answer per line.

Input
3
1 2
1 3
3
Q 1
C 2
Q 1
Output
3
2
*/

#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<string.h>
*/
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define RREP(i,s,t) for(int i=(s);i>=(t);--i)
#define ALL(x) (x).begin(),(x).end()
#define FILL(x,v) memset(x,v,sizeof(x))
#define LEN(x) sizeof(x)/sizeof(x[0])
#define MP(x,y) make_pair(x,y)
const int INF=0x3f3f3f3f;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
/*----------------------------------------------*/
const int N=100010;
struct edge{
    int to,next;
}edges[N<<1];
int head[N],tot;
int s[N],e[N];
int cnt;
int n;
char str[5];

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

void dfs(int u,int prev){
    ++cnt;
    s[u]=cnt;
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        if(v!=prev) dfs(v,u);
    }
    e[u]=cnt;
}

struct node{
    int l,r,sum;
}segTree[N<<2];

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].sum=1;
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}

void update(int i,int x){
    if(segTree[i].l==segTree[i].r){
        segTree[i].sum^=1;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(x<=mid) update(i<<1,x);
    else update((i<<1)|1,x);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}

int query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].sum;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid) return query(i<<1,l,r);
    else if(l>mid) return query((i<<1)|1,l,r);
    else return query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
}

int main(){
    int m;
    while(~scanf("%d",&n)){
        init();
        cnt=0;
        REP(i,1,n){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        dfs(1,0);
        build(1,1,n);
        scanf("%d",&m);
        while(m--){
            int x;
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d",&x);
                update(1,s[x]);
            }else{
                scanf("%d",&x);
                printf("%d\n",query(1,s[x],e[x]));
            }
        }
    }
}
