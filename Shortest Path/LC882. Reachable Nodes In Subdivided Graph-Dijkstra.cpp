/*
Starting with an undirected graph (the "original graph") with nodes from 0 to N-1, subdivisions are made to some of the edges.
The graph is given as follows: edges[k] is a list of integer pairs (i, j, n) such that (i, j) is an edge of the original graph,
and n is the total number of new nodes on that edge. 
Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1, x_2, ..., x_n) are added to the original graph,
and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) are added to the original graph.
Now, you start at node 0 from the original graph, and in each move, you travel along one edge. 
Return how many nodes you can reach in at most M moves.

Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
Output: 13
Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
Output: 23
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

const int MAXN=1000;
int adj[MAXN][MAXN];

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        
        int vis[N];
        int res=0;
        FILL(adj,-1);
        FILL(vis,0);
        for(VI edge:edges){
            adj[edge[0]][edge[1]]=edge[2];
            adj[edge[1]][edge[0]]=edge[2];
        }
        auto compare=[](const PII& a,const PII& b){return a.second<b.second;};
        priority_queue<PII,vector<PII>,decltype(compare)> pq(compare); //剩余步数类似于权值,从剩余步数最多的节点开始
        pq.push(MP(0,M));
        while(!pq.empty()){
            PII cur=pq.top();pq.pop();
            int u=cur.first,w=cur.second;
            if(vis[u]) continue;
            vis[u]=1;
            res++;
            REP(v,0,N){
                if(adj[u][v]==-1) continue;
                if(w>adj[u][v]&&!vis[v]) pq.push(MP(v,w-adj[u][v]-1)); //该节点有剩余步数
                adj[v][u]-=min(w,adj[u][v]); //更新当前路径上的node数量
                res+=min(w,adj[u][v]);
            }
        }
        return res;
    }
};
