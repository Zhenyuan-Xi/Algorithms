/*
Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. 
This means that the clover is covered by water for awhile and takes quite a long time to regrow. 
Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. 
Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, 
so he can control at what rate water flows into that ditch. 
Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, 
which feed out of the pond and into each other and stream in a potentially complex network. 
Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. 
For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle. 

Input
The input includes several cases. For each case, the first line contains two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). 
N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. 
Intersection 1 is the pond. Intersection point M is the stream. Each of the following N lines contains three integers, Si, Ei, and Ci. 
Si and Ei (1 <= Si, Ei <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from Si to Ei. 
Ci (0 <= Ci <= 10,000,000) is the maximum rate at which water will flow through the ditch.
Output
For each case, output a single integer, the maximum rate at which water may emptied from the pond.

Input
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
Output
50
*/

#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<string.h>
*/
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define RREP(i,s,t) for(int i=(s);i>=(t);--i)
#define ALL(x) (x).begin(),(x).end()
#define FILL(x,v) memset(x,v,sizeof(x))
#define LEN(x) sizeof(x)/sizeof(x[0])
#define MP(x,y) make_pair(x,y)
const int INF=0x3f3f3f3f;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
/*----------------------------------------------*/
const int N=210;
int mat[N][N];
int level[N];
int n,m;

bool bfs(int s,int t){ //BFS通过分层图寻找可行流
    FILL(level,-1);
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        REP(v,1,n+1){
            if(mat[u][v]>0&&~level[v]){ //未流过节点i并且cur->i还有残量
                level[v]=level[u]+1; //标记层数
                q.push(v);
            }
        }
    }
    return level[t]>0;
}

int dinic(int s,int t,int delta){ //DFS寻找增广路
    if(s==t) return delta;
    int flow;
    REP(i,1,n+1){
        if(level[i]==level[s]+1&&mat[s][i]>0&&(flow=dinic(i,t,min(delta,mat[s][i])))){ //满足分层图条件
                                                                                       //还有残量
                                                                                       //从该点出发以新的delta还可以找到增广路
            mat[s][i]-=flow;
            mat[i][s]+=flow;
            return flow;
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int res=0,tres=0;
    while(bfs(s,t)){ //当找到可行流时,进行dinic算法
        while(tres=dinic(s,t,INF)) res+=tres;
    }
    return res;
}

int main(){
    while(~scanf("%d%d",&m,&n)){
        FILL(mat,0);
        while(m--){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            mat[u][v]+=c; //初始化邻接矩阵
        }
        int res=max_flow(1,n);
        cout<<res<<endl;
    }
}
