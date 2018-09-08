/*
While exploring his many farms, Farmer John has discovered a number of amazing wormholes. 
A wormhole is very peculiar because it is a one-way path that delivers you to its destination at a time that is BEFORE you entered the wormhole! 
Each of FJ's farms comprises N (1 ≤ N ≤ 500) fields conveniently numbered 1..N, M (1 ≤ M ≤ 2500) paths, and W (1 ≤ W ≤ 200) wormholes.
As FJ is an avid time-traveling fan, he wants to do the following: start at some field, travel through some paths and wormholes, 
and return to the starting field a time before his initial departure. Perhaps he will be able to meet himself :) .
To help FJ find out whether this is possible or not, he will supply you with complete maps to F (1 ≤ F ≤ 5) of his farms. 
No paths will take longer than 10,000 seconds to travel and no wormhole can bring FJ back in time by more than 10,000 seconds.

Input
Line 1: A single integer, F. F farm descriptions follow. 
Line 1 of each farm: Three space-separated integers respectively: N, M, and W 
Lines 2..M+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: a bidirectional path between S and E that requires T seconds to traverse. 
Two fields might be connected by more than one path. 
Lines M+2..M+W+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: A one way path from S to E that also moves the traveler back T seconds.
Output
Lines 1..F: For each farm, output "YES" if FJ can achieve his goal, otherwise output "NO" (do not include the quotes).

Input
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
Output
NO
YES
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
const int N=1010;
int mat[N][N];
int dist[N];
int vis[N];
int cnt[N];
int n;
bool flg;

void spfa(int u){
    queue<int> q;
    dist[u]=0;
    vis[u]=1;
    cnt[u]++; //增加节点u入队次数
    q.push(u);
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        REP(v,1,n+1){
            if(dist[v]>dist[u]+mat[u][v]){
                dist[v]=dist[u]+mat[u][v];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]++; //增加节点v入队次数
                    if(cnt[v]>=n){flg=true;return;} //节点入队次数超过n次,存在环,即该节点可被多次更新直到为负无穷
                }
            }
        }
    }
}

int main(){
    int f,m,w;cin>>f;
    REP(ff,1,f+1){
        scanf("%d%d%d",&n,&m,&w);
        FILL(mat,0x3f);
        int s,e,t;
        REP(i,0,m){
            scanf("%d%d%d",&s,&e,&t);
            mat[s][e]=mat[e][s]=t;
        }
        REP(i,0,w){
            scanf("%d%d%d",&s,&e,&t);
            mat[s][e]=-t; //标记负权边
        }
        FILL(dist,0x3f);
        FILL(vis,0);
        FILL(cnt,0);
        flg=false;
        spfa(1);
        if(flg) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
