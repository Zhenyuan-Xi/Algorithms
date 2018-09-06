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
int mat[N][N];
int vis[N];
int dist[N];

int prim(int n){
    int u=1,res=0;
    vis[u]=1;
    REP(i,1,n+1) dist[i]=mat[u][i];
    int mmin;
    REP(i,1,n+1){
        mmin=INF;
        REP(j,1,n+1){
            if(!vis[j]&&mmin>dist[j]){
                mmin=dist[j];
                u=j;
            }
        }
        if(mmin==INF) return res;
        vis[u]=1;
        res+=mmin;
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]>mat[u][j]) dist[j]=mat[u][j];
        }
    }
}

int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        mat[u][v]=mat[v][u]=w;
    }
    int res=prim(n);
    cout<<res;
}
