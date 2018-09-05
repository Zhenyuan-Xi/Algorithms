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

int roads[110][110];
int vis[110],dist[110]; 

int prim(int n){
    int u=1,res=0;
    vis[u]=1;
    REP(i,1,n+1) dist[i]=roads[u][i];
    int mmin;
    REP(i,1,n+1){
        mmin=INF;
        REP(j,1,n+1){
            if(!vis[j]){
                if(mmin>dist[j]){
                    mmin=dist[j];
                    u=j;
                }
            }
        }
        if(mmin==INF) return res;
        vis[u]=1;
        res+=mmin;
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]>roads[u][j]) dist[j]=roads[u][j];
        }
    }
}

int main(){
    int n,m,a,b;cin>>n;
    FILL(vis,0);
    REP(i,1,n+1) REP(j,1,n+1) cin>>roads[i][j];
    cin>>m;
    REP(i,0,m){
        cin>>a>>b;
        roads[a][b]=0;
        roads[b][a]=0;
    }
    int res=prim(n);
    cout<<res;
}
