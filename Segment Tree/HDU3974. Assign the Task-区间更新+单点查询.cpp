/*
There is a company that has N employees(numbered from 1 to N),every employee in the company has a immediate boss (except for the leader of whole company).
If you are the immediate boss of someone,that person is your subordinate, and all his subordinates are your subordinates as well. 
If you are nobody's boss, then you have no subordinates,the employee who has no immediate boss is the leader of whole company.
So it means the N employees form a tree.
The company usually assigns some tasks to some employees to finish.
When a task is assigned to someone,He/She will assigned it to all his/her subordinates.
In other words,the person and all his/her subordinates received a task in the same time. 
Furthermore,whenever a employee received a task,he/she will stop the current task(if he/she has) and start the new one.
Write a program that will help in figuring out some employee’s current task after the company assign some tasks to some employee.

Input
The first line contains a single positive integer T( T <= 10 ), indicates the number of test cases.
For each test case:
The first line contains an integer N (N ≤ 50,000) , which is the number of the employees.
The following N - 1 lines each contain two integers u and v, which means the employee v is the immediate boss of employee u(1<=u,v<=N).
The next line contains an integer M (M ≤ 50,000).
The following M lines each contain a message which is either
"C x" which means an inquiry for the current task of employee x
or
"T x y"which means the company assign task y to employee x. (1<=x<=N,0<=y<=10^9)
Output
For each test case, print the test case number (beginning with 1) in the first line and then for every inquiry, output the correspond answer per line.
 
Input
1 
5 
4 3 
3 2 
1 3 
5 2 
5 
C 3 
T 2 1
 C 3 
T 3 2 
C 3
Output
Case #1:
-1 
1 
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
const int N=50050;
struct edge{
    int to,next;
}edges[N];
int head[N],tot;
int vis[N];
int s[N],e[N];
int cnt;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

void dfs(int u){
    ++cnt;
    s[u]=cnt;
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        dfs(v);
    }
    e[u]=cnt;
}

struct node{
    int l,r,task,lazy;
}segTree[N<<2];

void push_down(int i){
    if(segTree[i].l!=segTree[i].r&&segTree[i].lazy){
        segTree[i<<1].task=segTree[i].task;
        segTree[i<<1].lazy=1;
        segTree[(i<<1)|1].task=segTree[i].task;
        segTree[(i<<1)|1].lazy=1;
        segTree[i].lazy=0;
    }
}

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].task=-1;
    segTree[i].lazy=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}

void update(int i,int l,int r,int y){
    if(segTree[i].l==l&&segTree[i].r==r){
        segTree[i].task=y;
        segTree[i].lazy=1;
        return;
    }
    push_down(i);
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid) update(i<<1,l,r,y);
    else if(l>mid) update((i<<1)|1,l,r,y);
    else{
        update(i<<1,l,mid,y);
        update((i<<1)|1,mid+1,r,y);
    }
}

int query(int i,int x){
    if(segTree[i].l==x&&segTree[i].r==x) return segTree[i].task;
    push_down(i);
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(x<=mid) return query(i<<1,x);
    else return query((i<<1)|1,x);
}

int main(){
    int t,n,m;scanf("%d",&t);
    REP(i,1,t+1){
        scanf("%d",&n);
        printf("Case #%d:\n",i);
        init();
        cnt=0;
        FILL(vis,0);
        int u,v;
        REP(j,1,n){
            scanf("%d%d",&u,&v);
            vis[u]=1;
            addEdge(v,u);
        }
        REP(j,1,n+1){
            if(!vis[j]){
                dfs(j);
                break;
            }
        }
        build(1,1,cnt);
        char op[10];
        scanf("%d",&m);
        while(m--){
            int x,y;
            scanf("%s",op);
            if(op[0]=='C'){
                scanf("%d",&x);
                printf("%d\n",query(1,s[x]));
            }else{
                scanf("%d%d",&x,&y);
                update(1,s[x],e[x],y);
            }
        }
    }
}
