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
const int N=310;
int mat[N][N]; //邻接矩阵
int visx[N]; //记录每一轮匹配中已匹配的X点集
int visy[N]; //记录每一轮匹配中已匹配的Y点集
int lx[N]; //记录X点集的可行顶标
int ly[N]; //记录Y点集的可行顶标
int link[N]; //记录两个点集的匹配情况,link[y]=x代表x->y
int slack[N]; //松弛优化,记录两个点集中的点能够匹配还需要的最小值,slack[y]=w代表y被匹配还需要w
int nx,ny;

void init(){
    FILL(link,0);
    FILL(ly,0); //初始化Y点集的可行顶标为0
    REP(x,1,nx+1){
        lx[x]=-INF;
        REP(y,1,ny+1) lx[x]=max(lx[x],mat[x][y]); //初始化X点集的可行顶标为该点出边的最大边权
    }
}

bool find(int x){
    visx[x]=1;
    REP(y,1,ny+1){
        if(visy[y]) continue; //只参与一次匹配
        int gap=lx[x]+ly[y]-mat[x][y]; 
        if(gap==0){ //只使用可行边,即满足相等子图条件lx[x]+ly[y]=mat[x][y]的边
            visy[y]=1;
            if(!link[y]||find(link[y])){
                link[y]=x;
                return true;
            }
        }else slack[y]=min(slack[y],gap); //更新松弛量
    }
    return false;
}

int km(){
    init();
    REP(x,1,nx+1){ //为每个节点寻找匹配点
        FILL(slack,0x3f); 
        while(1){
            FILL(visx,0);
            FILL(visy,0);
            if(find(x)) break; //找到完全匹配
            int d=INF;
            REP(y,1,ny+1){
                if(!visy[y]) d=min(d,slack[y]); //求出增减量
            }
            REP(x,1,nx+1) if(visx[x]) lx[x]-=d; //X点集中已匹配的点的可行顶标减去增减量
            REP(y,1,ny+1){
                if(visy[y]) ly[y]+=d; //Y点集中已匹配的点的可行顶标加上增减量
                else slack[y]-=d; //更新松弛量
            }
        }
    }
    int res=0;
    REP(y,1,ny+1){
        //cout<<link[y]<<" "<<y<<" "<<mat[link[y]][y]<<endl;
        res+=mat[link[y]][y]; //统计边权
    }
    return res;
}

int main(){
    while(~scanf("%d%d",&nx,&ny)){
        REP(x,1,nx+1){
            REP(y,1,ny+1){
                int w;
                scanf("%d",&w);
                mat[x][y]=w; //构造邻接矩阵
            }
        }
        int res=km();
        cout<<res<<endl;
    }
}

/*
测试用例
Input
4 5
10 20 40 30 25
8 9 11 31 20
19 20 41 35 25
11 2 50 40 10
Output
126
*/
