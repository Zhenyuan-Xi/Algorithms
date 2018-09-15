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
const int N=510;
int mat[N][N]; //使用邻接矩阵保存边集
int vis[N];
int link[N];
int n;

bool hungarian(int u){
    REP(v,1,n+1){
        if(mat[u][v]&&!vis[v]){ //寻找与节点u相连并未访问过的节点v
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
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        mat[u][v]=1;
        mat[v][u]=1;
    }
    FILL(link,0);
    int res=0;
    REP(i,1,n+1){
        FILL(vis,0);
        if(hungarian(i)) res++;
    }
    cout<<res<<endl;
}

/*
测试用例
Input
6 5
1 2
1 3
1 4
2 5
3 6
Output
6
*/
