/*
There are N villages, which are numbered from 1 to N, and you should build some roads such that every two villages can connect to each other. 
We say two village A and B are connected, if and only if there is a road between A and B, 
or there exists a village C such that there is a road between A and C, and C and B are connected. 
We know that there are already some roads between some villages and your job is the build some roads 
such that all the villages are connect and the length of all the roads built is minimum.

Input
The first line is an integer N (3 <= N <= 100), which is the number of villages. 
Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance 
(the distance should be an integer within [1, 1000]) between village i and village j.
Then there is an integer Q (0 <= Q <= N * (N + 1) / 2). 
Then come Q lines, each line contains two integers a and b (1 <= a < b <= N), 
which means the road between village a and village b has been built.

Output
You should output a line contains an integer, which is the length of all the roads to be built 
such that all the villages are connected, and this value is minimum. 

Input
3
0 990 692
990 0 179
692 179 0
1
1 2
Output
179
/*

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
    int u=1,res=0; //以1为起点
    vis[u]=1;
    REP(i,1,n+1) dist[i]=roads[u][i]; //设置其余各顶点与当前顶点的距离
    int mmin; 
    REP(i,1,n+1){
        mmin=INF;
        REP(j,1,n+1){
            if(!vis[j]){
                if(mmin>dist[j]){ //找到当前顶点最近的未访问过的顶点
                    mmin=dist[j];
                    u=j;
                }
            }
        }
        if(mmin==INF) return res; //所有点都访问过则返回
        vis[u]=1;
        res+=mmin; //累积权值
        REP(j,1,n+1){
            if(!vis[j]&&dist[j]>roads[u][j]) dist[j]=roads[u][j]; //更新其余各顶点与当前顶点的距离
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
        roads[a][b]=0; //将已经连通的路径的权值设为0
        roads[b][a]=0;
    }
    int res=prim(n);
    cout<<res;
}
