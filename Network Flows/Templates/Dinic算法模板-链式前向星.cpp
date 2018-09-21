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
const int N=210;
struct edge{
    int to,next,cap;
}edges[N<<1];
int head[N],tot;
int level[N];
int n,m;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v,int cap){
    edges[tot].to=v;
    edges[tot].cap=cap;
    edges[tot].next=head[u];
    head[u]=tot++;
}

bool bfs(int s,int t){
    FILL(level,-1);
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t) return 1;
        for(int i=head[u];~i;i=edges[i].next){
            int v=edges[i].to,cap=edges[i].cap;
            if(cap>0&&level[v]==-1){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return level[t]>0;
}

int dinic(int s,int t,int delta){
    if(s==t) return delta;
    int flow;
    for(int i=head[s];~i;i=edges[i].next){
        int u=edges[i].to,cap=edges[i].cap;
        if(level[u]==level[s]+1&&cap>0&&(flow=dinic(u,t,min(delta,cap)))){
            edges[i].cap-=flow;
            edges[i^1].cap+=flow; //反向边增加delta,两条边的id关系:0^1=1,1^1=0;2^1=3,3^1=2
            return flow;
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int res=0,tres=0;
    while(bfs(s,t)){
        while(tres=dinic(s,t,INF)) res+=tres;
    }
    return res;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        while(m--){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,0); //建反向边
        }
        int res=max_flow(1,n);
        cout<<res<<endl;
    }
}

/*
测试用例
Input
4 5
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
Output
50
*/
