
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

const int MAXN=3000;
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
        priority_queue<PII,vector<PII>,decltype(compare)> pq(compare);
        pq.push(MP(0,M));
        while(!pq.empty()){
            PII cur=pq.top();pq.pop();
            int u=cur.first,w=cur.second;
            if(vis[u]) continue;
            vis[u]=1;
            res++;
            REP(v,0,N){
                if(adj[u][v]==-1) continue;
                if(w>adj[u][v]&&!vis[v]) pq.push(MP(v,w-adj[u][v]-1));
                adj[v][u]-=min(w,adj[u][v]);
                res+=min(w,adj[u][v]);
            }
        }
        return res;
    }
};
