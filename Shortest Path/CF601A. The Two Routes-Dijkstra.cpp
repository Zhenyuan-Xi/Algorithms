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
    int flg=mat[1][n]; //1:railway,0:bus
    int res=dijkstra(flg,n);
    cout<<res;
}
