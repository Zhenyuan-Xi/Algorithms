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
const int N=1010;
const int M=2010;
struct edge{ //链式前向星模板
    int to,next;
}edges[M];
int head[N],tot;
int vis[N]; //标记已访问过的节点
int link[N]; //连接已匹配的两个节点,link[v]=u即在增广路中u->v

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
            if(!link[v]||hungarian(link[v])){ //若节点v未匹配或从匹配节点v的节点可以找到另一条增广路,则将节点v匹配节点u,在增广路中u->v
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    int res=0;
    FILL(link,0);
    REP(i,1,n+1){
        FILL(vis,0);
        if(hungarian(i)) res++; //每找到一条增广路,根据增广路定理,匹配的节点数增加
    }
    cout<<res;
}
