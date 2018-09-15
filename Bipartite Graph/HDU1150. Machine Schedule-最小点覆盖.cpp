/*
As we all know, machine scheduling is a very classical problem in computer science and has been studied for a very long history. 
Scheduling problems differ widely in the nature of the constraints that must be satisfied and the type of schedule desired. 
Here we consider a 2-machine scheduling problem.
There are two machines A and B. Machine A has n kinds of working modes, which is called mode_0, mode_1, …, mode_n-1, 
likewise machine B has m kinds of working modes, mode_0, mode_1, … , mode_m-1. At the beginning they are both work at mode_0.
For k jobs given, each of them can be processed in either one of the two machines in particular mode. 
For example, job 0 can either be processed in machine A at mode_3 or in machine B at mode_4, job 1 can either be processed in machine A at mode_2 or in machine B at mode_4, and so on. 
Thus, for job i, the constraint can be represent as a triple (i, x, y), which means it can be processed either in machine A at mode_x, or in machine B at mode_y.
Obviously, to accomplish all the jobs, we need to change the machine's working mode from time to time, but unfortunately, the machine's working mode can only be changed by restarting it manually. 
By changing the sequence of the jobs and assigning each job to a suitable machine, please write a program to minimize the times of restarting machines. 
 
Input
The input file for this program consists of several configurations. The first line of one configuration contains three positive integers: n, m (n, m < 100) and k (k < 1000). 
The following k lines give the constrains of the k jobs, each line is a triple: i, x, y.
The input will be terminated by a line containing a single zero.
Output
The output should be one integer per line, which means the minimal times of restarting machine.
 
Input
5 5 10
0 1 1
1 1 2
2 1 3
3 1 4
4 2 1
5 2 2
6 2 3
7 2 4
8 3 3
9 4 3
0
Output
3
*/

#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
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
const int M=2010;
struct edge{
    int to,next;
}edges[M];
int head[N],tot;
int vis[N];
int link[N];
int n;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

bool hungarian(int u){
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        if(!vis[v]){
            vis[v]=1;
            if(!link[v]||hungarian(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m,k;
    while(scanf("%d%d%d",&n,&m,&k)==3){
        init();
        while(k--){
            int ii,u,v;
            scanf("%d%d%d",&ii,&u,&v); //找最少的点,覆盖所有边,即以mode数量为节点,每个job的两个mode之间为边,求最小点覆盖=最大匹配
            addEdge(u,v+n);
            addEdge(v+n,u);
        }
        FILL(link,0);
        int res=0;
        REP(i,1,n+1){
            FILL(vis,0);
            if(hungarian(i)) res++;
        }
        cout<<res<<endl;
    }
}
