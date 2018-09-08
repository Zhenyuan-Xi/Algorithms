#include <bits/stdc++.h>
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
const int N=100;
int mat[N][N]; //记录邻接矩阵
int dist[N]; //记录到达各点的最短距离
int pre[N]; //记录最短路径
int n;

void dijkstra(int u){
    queue<int> q; //未经堆优化
    q.push(u); //起点入队
    dist[u]=0; //初始化起点距离
    while(!q.empty()){
        u=q.front();q.pop(); //提取当前节点
        REP(v,1,n+1){ //松弛当前边,更新其余各点的最短距离
            if(dist[v]>dist[u]+mat[u][v]){ //找到到达v的更短路径
                dist[v]=dist[u]+mat[u][v]; //更新到达v的最短距离
                pre[v]=u; //记录当前路径
                q.push(v); //新节点入队
            }
        }
    }
}

void print(int u){ //打印最短路径
    if(pre[u]!=-1) print(pre[u]);
    printf("%d ",u);
}

int main(){
    int m;
    cin>>n>>m;    
    FILL(mat,0x3f);
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        mat[u][v]=mat[v][u]=w; //无向图初始化所有边
    }
    FILL(pre,-1);
    FILL(dist,0x3f);
    dijkstra(1);
    if(pre[n]==-1) cout<<-1;
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
