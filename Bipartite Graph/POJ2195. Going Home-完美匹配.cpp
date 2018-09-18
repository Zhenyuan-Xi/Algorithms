/*
On a grid map there are n little men and n houses. In each unit time, every little man can move one unit step, either horizontally, or vertically, to an adjacent point. 
For each little man, you need to pay a $1 travel fee for every step he moves, until he enters a house. 
The task is complicated with the restriction that each house can accommodate only one little man. 
Your task is to compute the minimum amount of money you need to pay in order to send these n little men into those n different houses. 
The input is a map of the scenario, a '.' means an empty space, an 'H' represents a house on that point, and am 'm' indicates there is a little man on that point. 
You can think of each point on the grid map as a quite large square, so it can hold n little men at the same time; 
also, it is okay if a little man steps on a grid with a house without entering that house.

Input
There are one or more test cases in the input. Each case starts with a line giving two integers N and M, where N is the number of rows of the map, and M is the number of columns. 
The rest of the input will be N lines describing the map. You may assume both N and M are between 2 and 100, inclusive. 
There will be the same number of 'H's and 'm's on the map; and there will be at most 100 houses. Input will terminate with 0 0 for N and M.
Output
For each test case, output one line with the single integer, which is the minimum amount, in dollars, you need to pay.

Input
2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
Output
2
10
28
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
char grid[N][N];
int xx[N],xy[N],yx[N],yy[N]; //存储输入图以及各点之间x轴y轴距离

int mat[N][N];
int visx[N];
int visy[N];
int lx[N];
int ly[N];
int link[N];
int slack[N];
int nx,ny;

void init(){
    FILL(link,-1);
    FILL(ly,0);
    REP(x,0,nx){
        lx[x]=-INF;
        REP(y,0,ny) lx[x]=max(lx[x],mat[x][y]);
    }
}

bool find(int x){
    visx[x]=1;
    REP(y,0,ny){
        if(visy[y]) continue;
        int gap=lx[x]+ly[y]-mat[x][y];
        if(gap==0){
            visy[y]=1;
            if(link[y]==-1||find(link[y])){
                link[y]=x;
                return true;
            }
        }else slack[y]=min(slack[y],gap);
    }
    return false;
}

int km(){
    init();
    REP(x,0,nx){
        FILL(slack,0x3f);
        while(1){
            FILL(visx,0);
            FILL(visy,0);
            if(find(x)) break;
            int d=INF;
            REP(y,0,ny){
                if(!visy[y]) d=min(d,slack[y]);
            }
            REP(x,0,nx) if(visx[x]) lx[x]-=d;
            REP(y,0,ny){
                if(visy[y]) ly[y]+=d;
                else slack[y]-=d;
            }
        }
    }
    int res=0;
    REP(y,0,ny){
        res+=mat[link[y]][y];
    }
    return res;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m){
        nx=ny=0;
        REP(i,0,n) scanf("%s",grid[i]);
        REP(i,0,n){
            REP(j,0,m){
                if(grid[i][j]=='m'){ //统计X点集中的点的x轴y轴位置
                    xx[nx]=i;
                    xy[nx]=j;
                    nx++;
                }else if(grid[i][j]=='H'){ //统计Y点集中的点的x轴y轴位置
                    yx[ny]=i;
                    yy[ny]=j;
                    ny++;
                }
            }
            REP(x,0,nx){
                REP(y,0,ny){
                    mat[x][y]=-(abs(xx[x]-yx[y])+abs(xy[x]-yy[y])); //初始化邻接矩阵,边权为各个x点和y点之间的曼哈顿距离
                                                                    //由于要求最小权完美匹配,即将边权取负值后用KM算法求最大权完美匹配
                }
            }
        }
        int res=km();
        cout<<-res<<endl;
    }
}
