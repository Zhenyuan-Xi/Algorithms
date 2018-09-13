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
VI adj[N];
VI res[2];
int colors[N];
bool ok;

void dfs(int u,int color){
    if(!ok) return;
    if(colors[u]!=-1){
        ok=colors[u]==color; //判断当前已经被染色的节点的颜色是否等于它应该是的颜色
        return;
    }
    colors[u]=color; //将当前节点染色
    res[color].push_back(u); //放入该颜色的集合里
    REP(i,0,adj[u].size()){
        dfs(adj[u][i],color^1); //对当前节点邻接的所有节点,尝试将它们染成另一种颜色,0->1,1->0
    }
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v); //建邻接表
        adj[v].push_back(u);
    }
    FILL(colors,-1);
    ok=true;
    REP(i,1,n+1){
        if(colors[i]==-1) //从未染色的节点开始 
           dfs(i,0); 
    }
    if(!ok) cout<<-1<<endl;
    else{
        REP(i,0,res[0].size())
            cout<<res[0][i]<<" ";
        cout<<endl;
        REP(i,0,res[1].size())
            cout<<res[1][i]<<" ";
    }
}

/*
测试用例
Input
4 2
1 2
2 3
Output
2 
1 3 4
*/
