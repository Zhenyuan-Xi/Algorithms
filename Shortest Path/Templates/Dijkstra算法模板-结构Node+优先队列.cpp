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
int pre[N]; //存放最短路径
int dist[N]; //存放各点到起点的最短距离
struct node{ //结构Node,存放index以及到该节点的边权
    int idx,w;
    node(){}
    node(int _idx,int _w){idx=_idx;w=_w;}
    bool operator < (const node& node) const{ //重写操作符,边权最小的节点在队头
        if(w==node.w) return idx<node.idx;
        else return w>node.w;
    }
};
vector<node> adj[N]; //结构Node邻接表,adj[u]=node(v,w)为u->v=w
priority_queue<node> pq; //使用优先队列进行堆优化

void dijkstra(){
    dist[1]=0; //初始化起点最短距离
    pq.push(node(1,0)); //起点入队
    while(!pq.empty()){
        node u=pq.top();pq.pop(); //提取队头,即到当前节点距离最短的节点
        for(node v:adj[u.idx]){ //松弛此边
            if(dist[v.idx]>dist[u.idx]+v.w){ //找到到节点v的更短路径
                dist[v.idx]=dist[u.idx]+v.w; //更新到节点v的最短距离
                pre[v.idx]=u.idx; //更新节点v的前驱节点
                pq.push(node(v.idx,dist[v.idx])); //新节点v入队
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
        adj[u].push_back(node(v,w)); //初始化邻接表
        adj[v].push_back(node(u,w));
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
