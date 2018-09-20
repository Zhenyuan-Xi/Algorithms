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
int mat[N][N];
int level[N];
int n,m;

bool bfs(int s,int t){ //BFS通过分层图寻找可行流
    FILL(level,-1);
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t) return true;
        REP(v,1,n+1){
            if(mat[u][v]>0&&level[v]==-1){ //未流过节点i并且cur->i还有残量
                level[v]=level[u]+1; //标记层数
                q.push(v);
            }
        }
    }
    return level[t]>0;
}

int dinic(int s,int t,int delta){ //DFS寻找增广路
    if(s==t) return delta;
    int flow;
    REP(i,1,n+1){
        if(level[i]==level[s]+1&&mat[s][i]>0&&(flow=dinic(i,t,min(delta,mat[s][i])))){ //满足分层图条件
                                                                                       //还有残量
                                                                                       //从该点出发以新的delta还可以找到增广路
            mat[s][i]-=flow;
            mat[i][s]+=flow;
            return flow;
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int res=0,tres=0;
    while(bfs(s,t)){ //当找到可行流时,进行dinic算法
        while(tres=dinic(s,t,INF)) res+=tres;
    }
    return res;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        FILL(mat,0);
        while(m--){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            mat[u][v]=c; //初始化邻接矩阵(无重边),mat[u][v]+=c(有重边)
        }
        int res=max_flow(1,n);
        cout<<res<<endl;
    }
}

/*
测试用例
Input
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
Output
50
*/
