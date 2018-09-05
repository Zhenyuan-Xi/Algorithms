/*
某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。
请计算最小的公路总长度。

Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；
随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
当N为0时，输入结束，该用例不被处理。

Output
对每个测试用例，在1行里输出最小的公路总长度。

Input
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
Output
3
5
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

const int N=105;
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
            if(!vis[j]&&mmin>dist[j]){ //取与当前节点最近的节点
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
    int n,u,v,w;
    while(scanf("%d",&n)&&n){
        FILL(vis,0);
        int m=(n-1)*n/2;
        REP(i,1,m+1){
            scanf("%d%d%d",&u,&v,&w);
            mat[u][v]=mat[v][u]=w;
        }
        int res=prim(n);
        cout<<res<<endl;
    }
}
