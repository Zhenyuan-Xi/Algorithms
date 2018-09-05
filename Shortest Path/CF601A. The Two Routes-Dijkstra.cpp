/*
In Absurdistan, there are n towns (numbered 1 through n) and m bidirectional railways. 
There is also an absurdly simple road network — for each pair of different towns x and y, 
there is a bidirectional road between towns x and y if and only if there is no railway between them. 
Travelling to a different town using one railway or one road always takes exactly one hour.
A train and a bus leave town 1 at the same time. They both have the same destination, town n, 
and don't make any stops on the way (but they can wait in town n). The train can move only along railways and the bus can move only along roads.
You've been asked to plan out routes for the vehicles; each route can use any road/railway multiple times. 
One of the most important aspects to consider is safety — in order to avoid accidents at railway crossings, 
the train and the bus must not arrive at the same town (except town n) simultaneously.
Under these constraints, what is the minimum number of hours needed for both vehicles to reach town n (the maximum of arrival times of the bus and the train)? 
Note, that bus and train are not required to arrive to the town n at the same moment of time, but are allowed to do so.

Input
The first line of the input contains two integers n and m (2 ≤ n ≤ 400, 0 ≤ m ≤ n(n - 1) / 2) — the number of towns and the number of railways respectively.
Each of the next m lines contains two integers u and v, denoting a railway between towns u and v (1 ≤ u, v ≤ n, u ≠ v).
You may assume that there is at most one railway connecting any two towns.
Output
Output one integer — the smallest possible time of the later vehicle's arrival in town n. 
If it's impossible for at least one of the vehicles to reach town n, output  - 1.
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
const int N=405;
int dist[N];
int mat[N][N];

int dijkstra(int flg,int n){
    FILL(dist,-1);
    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        REP(v,1,n+1){
            if(mat[u][v]!=flg&&dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[n];
}

int main(){
    int n,m,x,y;cin>>n>>m;
    REP(i,0,m){
        scanf("%d%d",&x,&y);
        mat[x][y]=mat[y][x]=1;
    }
    int flg=mat[1][n]; //1:railway,0:bus,其中一个到达终点的路径必为1,即求另一个的最短路径
    int res=dijkstra(flg,n);
    cout<<res;
}
