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
vector<PII> edges(N); //存放边,PII=(u,v)

int main(){
    int n;scanf("%d",&n); //输入节点数量
    REP(i,0,n){
        int u,v;
        scanf("%d%d",&u,&v);
        edges.push_back(MP(u,v)); //输入边
    }
    unordered_map<int,unordered_set<int>> adj; //邻接表,u->(v,w,x,y,z) 
    unordered_map<int,int> indegree; //入度表,u->0,v->1,w->1
    REP(i,0,edges.size()){ //初始化邻接表和入度表
        int u=edges[i].first,v=edges[i].second; //提取u,v节点
        if(indegree.find(u)==indegree.end()) indegree[u]=0; //初始化根节点入度为0
        if(adj[u].find(v)==adj[u].end()){ //检查是否以存放
            adj[u].insert(v); //存放进邻接表
            indegree[v]++; //增加v节点入度
        }
    }
    queue<int> q; //以队列存储节点进行遍历
    int cnt=0; //记录入度为0的节点的数量
    REP(i,0,n){
        if(indegree[i]==0) q.push(i); //将初始入度为0的节点存进队列
    }
    while(!q.empty()){
        int size=q.size();
        REP(i,0,size){
            int u=q.front(),q.pop();
            cnt++;
            for(int v:adj[u]){ //检查u可到达的每个v节点
                indegree[v]--; //降低v节点入度,即移除边u->v
                if(indegree[v]==0) q.push(v); //若v节点入度为0,存进队列
            }
        }
    }
    if(cnt!=n) cout<<"Not Valid"; //检查是否存在环,若有多余的边,则存在环
    cout<<"Valid";
}
