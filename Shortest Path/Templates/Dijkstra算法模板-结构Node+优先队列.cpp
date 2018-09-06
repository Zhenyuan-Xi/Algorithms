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
int pre[N];
int dist[N];
struct node{
    int idx,w;
    node(){}
    node(int _idx,int _w){idx=_idx;w=_w;}
    bool operator < (const node& node) const{
        if(w==node.w) return idx<node.idx;
        else return w>node.w;
    }
};
vector<node> adj[N];
priority_queue<node> pq;

void dijkstra(){
    dist[1]=0;
    pq.push(node(1,0));
    while(!pq.empty()){
        node u=pq.top();pq.pop();
        for(node v:adj[u.idx]){
            if(dist[v.idx]>dist[u.idx]+v.w){
                dist[v.idx]=dist[u.idx]+v.w;
                pre[v.idx]=u.idx;
                pq.push(node(v.idx,dist[v.idx]));
            }
        }
    }
}

void print(int u){
    if(pre[u]!=-1) print(pre[u]);
    printf("%d ",u);
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(node(v,w));
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
