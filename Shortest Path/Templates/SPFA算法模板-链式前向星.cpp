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
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define RREP(i,s,t) for(int i=(s);i>=(t);i--)
#define ALL(x) (x).begin(),(x).end()
#define FILL(x,v) memset(x,v,sizeof(x))
#define LEN(x) sizeof(x)/sizeof(x[0])
#define MP(x,y) make_pair(x,y)
const int INF=0x3f3f3f3f;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
/*----------------------------------------------*/
const int N=1010;
struct node{ //结构Node,构造链式前向星作为静态邻接表
    int to,next,w;
}mat[N];
int dist[N];
int vis[N];
int head[N]; //标记头节点下标
int pre[N];
int cnt[N];
int n;
int idx; //Node的下标
bool cycle; 

void addEdge(int u,int v,int w){
    mat[idx].next=head[u]; //链接节点u能到达的各节点
    mat[idx].to=v;
    mat[idx].w=w;
    head[u]=idx++;
}

void spfa(int u){
    queue<int> q;
    q.push(u);
    vis[u]=1;
    cnt[u]++;
    dist[u]=0;
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=mat[i].next){ //检查以节点u起始的所有节点
            int v=mat[i].to,w=mat[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pre[v]=u;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]++;
                    if(cnt[v]>=n){cycle=true;return;}
                }
            }
        }
    }
}

void print(int u){
    if(pre[u]!=-1) print(pre[u]);
    printf("%d ",u);
}

int main(){
    int m;
    cin>>n>>m;
    idx=1;
    FILL(head,-1);
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    cycle=false;
    FILL(cnt,0);
    FILL(pre,-1);
    FILL(dist,0x3f);
    FILL(vis,0);
    spfa(1);
    if(cycle) cout<<"have cycle";
    else if(pre[n]==-1) cout<<-1;
    else print(n);
}

/*
测试用例
Input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
Output
1 4 3 5
*/
