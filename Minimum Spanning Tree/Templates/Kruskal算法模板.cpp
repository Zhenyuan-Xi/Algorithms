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
int id[N],size[N]; //union by size和path compression
struct edge{
    int u,v,w;
}edges[N*(N-1)/2]; //构造边

int compare(edge a,edge b){return a.w<b.w;} //按权值从小到大排序

int find(int u){
    while(u!=id[u]){u=id[u];id[u]=id[id[u]];}
    return u;
}

void uni(int u,int v){
    int uu=find(u),vv=find(v);
    if(size[uu]>size[vv]){id[vv]=uu;size[uu]+=size[vv];}
    else {id[uu]=vv;size[vv]+=size[uu];}
}

int main(){
    int n,m,u,v,w;
    cin>>n;
    m=n*(n-1)/2;
    REP(i,1,n+1) id[i]=i;
    FILL(size,1);
    REP(i,1,m+1) scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w); //初始化所有边
    sort(edges+1,edges+m+1,compare); //将所有边按权值从小到大排序
    int res=0;
    REP(i,1,m+1){
        if(find(edges[i].u)!=find(edges[i].v)){ //每次取权值最小的且两节点还未连通的边
            res+=edges[i].w; //累计权值
            uni(edges[i].u,edges[i].v); //连通两节点
        }
    }
    cout<<res;
}
