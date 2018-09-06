/*
You are given a weighted undirected graph. The vertices are enumerated from 1 to n. 
Your task is to find the shortest path between the vertex 1 and the vertex n.
Dijkstra模板题,找到1->n最短路径并打印。
Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), 
where n is the number of vertices and m is the number of edges. 
Following m lines contain one edge each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), 
where ai, bi are edge endpoints and wi is the length of the edge.
It is possible that the graph has loops and multiple edges between pair of vertices.
Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. 
If there are many solutions, print any of them.

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
const ll LINF=1e18;
vector<PII> adj[100005];
ll dist[100005];
int pre[100005];
priority_queue<PII,vector<PII>,greater<PII>> pq;

void print(int v){
    if(pre[v]!=-1) print(pre[v]);
    printf("%d ",v);
}

int main(){
    int n,m,u,v,w;cin>>n>>m;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(MP(w,v));
        adj[v].push_back(MP(w,u));
    }
    FILL(pre,-1);
    fill_n(dist+1,n,LINF);
    pq.push(MP(0,1));
    dist[1]=0;
    while(!pq.empty()){
        u=pq.top().second;pq.pop();
        for(PII edge:adj[u]){
            v=edge.second,w=edge.first;
            if(dist[v]>w+dist[u]){
                dist[v]=w+dist[u];
                pq.push(MP(dist[v],v));
                pre[v]=u;
            }
        }
    }
    if(pre[n]==-1) cout<<-1;
    else print(n);
}
