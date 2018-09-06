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
vector<PII> adj[N]; //用邻接表存储边
int pre[N]; //存放最短路径
int dist[N]; //存放各节点到起点的最短距离
priority_queue<PII,vector<PII>,greater<PII>> pq; //使用优先队列进行堆优化

void dijkstra(){
    pq.push(MP(0,1)); //起始节点入队
    dist[1]=0; //起始节点最短距离初始化
    while(!pq.empty()){
        int u=pq.top().second;pq.pop(); //提取与当前节点距离最近的节点
        for(PII edge:adj[u]){ //松弛此边
            int v=edge.second,w=edge.first;  
            if(dist[v]>dist[u]+w){ //找到到节点v的更短的路径
                dist[v]=dist[u]+w; //更新到节点v的最短距离
                pre[v]=u; //更新节点v的前驱节点
                pq.push(MP(dist[v],v)); //新节点v入队
            }
        }
    }
}

void print(int u){ //打印最短路径
    if(pre[u]!=-1) print(pre[u]);
    printf("%d ",u);
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(MP(w,v)); //初始化无向图邻接表
        adj[v].push_back(MP(w,u));
    }
    FILL(pre,-1);
    FILL(dist,0x3f);
    dijkstra();
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
