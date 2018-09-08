/*
Okabe likes to be able to walk through his city on a path lit by street lamps. That way, he doesn't get beaten up by schoolchildren.
Okabe's city is represented by a 2D grid of cells. Rows are numbered from 1 to n from top to bottom, and columns are numbered 1 to m from left to right. 
Exactly k cells in the city are lit by a street lamp. It's guaranteed that the top-left cell is lit.
Okabe starts his walk from the top-left cell, and wants to reach the bottom-right cell. Of course, Okabe will only walk on lit cells, 
and he can only move to adjacent cells in the up, down, left, and right directions. 
However, Okabe can also temporarily light all the cells in any single row or column at a time if he pays 1 coin, allowing him to walk through some cells not lit initially.
Note that Okabe can only light a single row or column at a time, and has to pay a coin every time he lights a new row or column. 
To change the row or column that is temporarily lit, he must stand at a cell that is lit initially. 
Also, once he removes his temporary light from a row or column, all cells in that row/column not initially lit are now not lit.
Help Okabe find the minimum number of coins he needs to pay to complete his walk!

Input
The first line of input contains three space-separated integers n, m, and k (2 ≤ n, m, k ≤ 104).
Each of the next k lines contains two space-separated integers ri and ci (1 ≤ ri ≤ n, 1 ≤ ci ≤ m) — the row and the column of the i-th lit cell.
It is guaranteed that all k lit cells are distinct. It is guaranteed that the top-left cell is lit.
Output
Print the minimum number of coins Okabe needs to pay to complete his walk, or -1 if it's not possible.

Input
4 4 5
1 1
2 1
2 3
3 3
4 3
Output
2

Input
5 5 4
1 1
2 1
3 1
3 2
Output
-1

Input
2 2 4
1 1
1 2
2 1
2 2
Output
0
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
const int N=10010;
struct node{
    int x,y;
}mat[N]; //构建点集,无需邻接表因为只能去相邻的四个节点
int dist[N];
int vis[N];
int n,m,k;

void spfa(int u){
    queue<int> q;
    q.push(u);
    dist[u]=0;
    vis[u]=1;
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        REP(v,1,k+1){
            if(u==v) continue;
            int w=INF,distx=abs(mat[u].x-mat[v].x),disty=abs(mat[u].y-mat[v].y); //检查各点与当前节点的距离
            if(distx+disty==1) w=0; //相邻则边权为0,无需点亮
            else if(distx<=2||disty<=2) w=1; //间隔一行或一列则边权为1,需点亮间隔的行或列
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

int main(){
    int flg=0;
    scanf("%d%d%d",&n,&m,&k);
    REP(i,1,k+1){
        int u,v;
        scanf("%d%d",&mat[i].x,&mat[i].y);
        if(mat[i].x==n&&mat[i].y==m) flg=1; //检查终点节点是否点亮
    }
    if(!flg){ //若终点(n,m)未点亮,点亮(n+1,m+1)并作为终点节点
        mat[++k].x=n+1;
        mat[k].y=m+1;
    }
    FILL(dist,0x3f);
    FILL(vis,0);
    spfa(1);
    if(dist[k]==INF) cout<<-1;
    else cout<<dist[k];
}
