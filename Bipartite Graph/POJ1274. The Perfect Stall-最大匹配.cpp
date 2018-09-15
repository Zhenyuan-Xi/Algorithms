/*
Farmer John completed his new barn just last week, complete with all the latest milking technology. 
Unfortunately, due to engineering problems, all the stalls in the new barn are different. 
For the first week, Farmer John randomly assigned cows to stalls, but it quickly became clear that any given cow was only willing to produce milk in certain stalls. 
For the last week, Farmer John has been collecting data on which cows are willing to produce milk in which stalls. 
A stall may be only assigned to one cow, and, of course, a cow may be only assigned to one stall. 
Given the preferences of the cows, compute the maximum number of milk-producing assignments of cows to stalls that is possible. 

Input
The input includes several cases. For each case, the first line contains two integers, N (0 <= N <= 200) and M (0 <= M <= 200). 
N is the number of cows that Farmer John has and M is the number of stalls in the new barn. 
Each of the following N lines corresponds to a single cow. The first integer (Si) on the line is the number of stalls that the cow is willing to produce milk in (0 <= Si <= M). 
The subsequent Si integers on that line are the stalls in which that cow is willing to produce milk. The stall numbers will be integers in the range (1..M), and no stall will be listed twice for a given cow.
Output
For each case, output a single line with a single integer, the maximum number of milk-producing stall assignments that can be made.

Input
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2 
Output
4
*/

#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
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
const int N=210;
const int M=40010;
struct edge{
    int to,next;
}edges[M];
int head[N],tot;
int vis[N];
int link[N];
int n;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

bool hungarian(int u){
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        if(!vis[v]){
            vis[v]=1;
            if(!link[v]||hungarian(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m;
    while(~scanf("%d%d",&n,&m)){
        init();
        REP(u,1,n+1){
            int s;
            scanf("%d",&s);
            while(s--){
                int v;
                scanf("%d",&v);
                addEdge(u,v); //牛->棚,只需计算最大匹配时的牛的数量所以不需要棚->牛的边
            }
        }
        FILL(link,0);
        int res=0;
        REP(i,1,n+1){
            FILL(vis,0);
            if(hungarian(i)) res++;
        }
        cout<<res<<endl;
    }
}
