/*
One cow from each of N farms (1 ≤ N ≤ 1000) conveniently numbered 1..N is going to attend the big cow party to be held at farm #X (1 ≤ X ≤ N). 
A total of M (1 ≤ M ≤ 100,000) unidirectional (one-way roads connects pairs of farms; road i requires Ti (1 ≤ Ti ≤ 100) units of time to traverse.
Each cow must walk to the party and, when the party is over, return to her farm. Each cow is lazy and thus picks an optimal route with the shortest time. 
A cow's return route might be different from her original route to the party since roads are one-way.
Of all the cows, what is the longest amount of time a cow must spend walking to the party and back?

Input
Line 1: Three space-separated integers, respectively: N, M, and X 
Lines 2..M+1: Line i+1 describes road i with three space-separated integers: Ai, Bi, and Ti. 
The described road runs from farm Ai to farm Bi, requiring Ti time units to traverse.
Output
Line 1: One integer: the maximum of time any one cow must walk.

Input
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
Output
10
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
const int N=1005;
int mat[N][N];
int dist[N];
int res1[N],res2[N];
int vis[N];
int n;

void dijkstra(int u){ //未经堆优化的Dijkstra模板
    dist[u]=0;
    REP(i,1,n+1){
        int mmin=INF,v=0;
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]<mmin){
                mmin=dist[j];
                v=j;
            }
        }
        vis[v]=1;
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]>dist[v]+mat[v][j]){
                dist[j]=dist[v]+mat[v][j];
            }
        }
    }
}

int main(){
    int m,x;
    cin>>n>>m>>x;
    FILL(vis,0);
    FILL(dist,0x3f);
    FILL(mat,0x3f);
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        mat[u][v]=w;
    }
    dijkstra(x);
    REP(i,1,n+1) res1[i]=dist[i];
    FILL(vis,0);
    FILL(dist,0x3f);
    REP(i,1,n+1) REP(j,i+1,n+1) swap(mat[i][j],mat[j][i]); //转置矩阵,即u->v变为v->u,实现以各节点为起点,x为终点
    dijkstra(x);
    REP(i,1,n+1) res2[i]=dist[i];
    int res=0;
    REP(i,1,n+1) res=max(res,res1[i]+res2[i]);
    cout<<res;
}
