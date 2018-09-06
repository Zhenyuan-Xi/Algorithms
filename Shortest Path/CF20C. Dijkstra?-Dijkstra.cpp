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
