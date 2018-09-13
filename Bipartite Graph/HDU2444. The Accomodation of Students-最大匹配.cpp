/*
There are a group of students. Some of them may know each other, while others don't. For example, A and B know each other, B and C know each other. 
But this may not imply that A and C know each other. Now you are given all pairs of students who know each other. 
Your task is to divide the students into two groups so that any two students in the same group don't know each other.
If this goal can be achieved, then arrange them into double rooms. 
Remember, only paris appearing in the previous given set can live in the same room, which means only known students can live in the same room.
Calculate the maximum number of pairs that can be arranged into these double rooms.

Input
For each data set:
The first line gives two integers, n and m(1<n<=200), indicating there are n students and m pairs of students who know each other. The next m lines give such pairs.
Proceed to the end of file.
Output
If these students cannot be divided into two groups, print "No". Otherwise, print the maximum number of pairs that can be arranged in those rooms.
 
Input
4 4
1 2
1 3
1 4
2 3
6 5
1 2
1 3
1 4
2 5
3 6
Output
No
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
const int M=410;
struct edge{ //链式前向星构造邻接表
    int to,next;
}edges[M];
int head[N],tot;
int colors[N];
int vis[N];
int link[N];
int n;
bool ok;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

void dfs(int u,int color){
    if(!ok) return;
    if(colors[u]!=-1){
        ok=colors[u]==color;
        return;
    }
    colors[u]=color;
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        dfs(v,color^1);
    }
}

bool hungarian(int u){
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        if(!vis[v]){
            vis[v]=1;
            if(link[v]==-1||hungarian(link[v])){ //节点v未匹配或从节点v的匹配点可以找到另一条增广路
                link[v]=u; //匹配节点u和v,添加增广路路径u->v
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        ok=true;
        int res=0;
        FILL(colors,-1);
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        REP(i,1,n+1){
            if(colors[i]==-1) dfs(i,0); //判断是否为二分图
        }
        if(!ok) cout<<"No"<<endl;
        else{
            FILL(link,-1);
            REP(i,1,n+1){
                FILL(vis,0);
                if(hungarian(i)) res++; //找到一条增广路,则增加匹配数
            }
            cout<<res/2<<endl;
        }
    }
}
