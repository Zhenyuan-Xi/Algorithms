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
const int N=1000;
int mat[N][N]; //存放边
int vis[N]; //记录访问过的节点
int dist[N]; //记录各节点与当前节点的距离

int prim(int n){
    int u=1,res=0; //从节点1开始
    vis[u]=1; //标记访问
    REP(i,1,n+1) dist[i]=mat[u][i]; //初始化各节点与u的距离
    int mmin;
    REP(i,1,n+1){
        mmin=INF;
        REP(j,1,n+1){
            if(!vis[j]&&mmin>dist[j]){ //找出与当前节点距离最短的未访问过的节点作为下一个节点
                mmin=dist[j]; //更新最短距离
                u=j; //更新当前节点
            }
        }
        if(mmin==INF) return res; //节点都已经访问过,返回
        vis[u]=1; //标记访问
        res+=mmin; //累计权值
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]>mat[u][j]) dist[j]=mat[u][j]; //更新未访问过的各节点与当前节点的距离
        }
    }
}

int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        mat[u][v]=mat[v][u]=w; //输入边及权值
    }
    int res=prim(n);
    cout<<res;
}
