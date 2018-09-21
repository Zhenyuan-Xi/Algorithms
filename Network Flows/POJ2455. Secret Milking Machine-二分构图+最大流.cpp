/*
Farmer John is constructing a new milking machine and wishes to keep it secret as long as possible. 
He has hidden in it deep within his farm and needs to be able to get to the machine without being detected. 
He must make a total of T (1 <= T <= 200) trips to the machine during its construction. 
He has a secret tunnel that he uses only for the return trips. 
The farm comprises N (2 <= N <= 200) landmarks (numbered 1..N) connected by P (1 <= P <= 40,000) bidirectional trails (numbered 1..P) 
and with a positive length that does not exceed 1,000,000. Multiple trails might join a pair of landmarks. 
To minimize his chances of detection, FJ knows he cannot use any trail on the farm more than once and that he should try to use the shortest trails. 
Help FJ get from the barn (landmark 1) to the secret milking machine (landmark N) a total of T times. 
Find the minimum possible length of the longest single trail that he will have to use, subject to the constraint that he use no trail more than once. 
(Note well: The goal is to minimize the length of the longest trail, not the sum of the trail lengths.) 
It is guaranteed that FJ can make all T trips without reusing a trail.

Input
* Line 1: Three space-separated integers: N, P, and T 
* Lines 2..P+1: Line i+1 contains three space-separated integers, A_i, B_i, and L_i, 
indicating that a trail connects landmark A_i to landmark B_i with length L_i.
Output
* Line 1: A single integer that is the minimum possible length of the longest segment of Farmer John's route.

Input
7 9 2
1 2 2
2 3 5
3 7 5
1 4 1
4 3 1
4 5 7
5 7 1
1 6 3
6 7 3
Output
5
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
const int M=40010;
struct edge{
    int to,next,cap;
}edges[M<<1];
int head[N],tot;
int level[N];
int cur[N]; //当前弧优化
int mat[M<<1][3];
int n,p,t;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v,int cap){
    edges[tot].to=v;
    edges[tot].cap=cap;
    edges[tot].next=head[u];
    head[u]=tot++;
}

bool bfs(int s,int t){
    FILL(level,-1);
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t) return true;
        for(int i=head[u];~i;i=edges[i].next){
            int v=edges[i].to,cap=edges[i].cap;
            if(cap>0&&level[v]==-1){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return level[t]>0;
}

int dinic(int s,int t,int delta){
    if(s==t) return delta;
    int flow;
    for(int i=cur[s];~i;i=edges[i].next){
        cur[s]=i; //更新当前弧,避免重复计算已经满流的边
        int u=edges[i].to,cap=edges[i].cap;
        if(level[u]==level[s]+1&&cap>0&&(flow=dinic(u,t,min(delta,cap)))){
            edges[i].cap-=flow;
            edges[i^1].cap+=flow;
            return flow;
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int res=0,tres=0;
    while(bfs(s,t)){
        REP(i,1,n+1) cur[i]=head[i]; //拷贝头数组到当前弧
        while(tres=dinic(s,t,INF)) res+=tres;
    }
    return res;
}

int main(){
    while(~scanf("%d%d%d",&n,&p,&t)){
        int l=INF,r=-1,res=0,cnt=0;
        REP(i,1,p+1){
            scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
            l=min(l,mat[i][2]); //寻找边权的下界
            r=max(r,mat[i][2]); //寻找边权的上界
        }
        while(l<=r){
            int m=l+(r-l)/2; //二分查找
            init();
            REP(i,1,p+1){
                if(mat[i][2]<=m){ //用小于二分边权的边建图,容量为1,即最大流为起点到终点的路径数量
                    addEdge(mat[i][0],mat[i][1],1);
                    addEdge(mat[i][1],mat[i][0],1);
                }
            }
            cnt=max_flow(1,n); //求当前边能得到的路径数量
            if(cnt>=t) r=m-1; //缩小二分边界
            else l=m+1;
        }
        cout<<l<<endl;
    }
}
