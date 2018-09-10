/*
在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的t-shirt。但是每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是非常累的！
所以现在他们想要寻找最短的从商店到赛场的路线，你可以帮助他们吗？

Input
输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M则表示在成都有几条路。
N=M=0表示输入结束。接下来M行，每行包括3个整数A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口A与路口B之间有一条路，我们的工作人员需要C分钟的时间走过这条路。
输入保证至少存在1条商店到赛场的路线。
Output
对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间
 
Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
Output
3
2
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
const int N=110;
int n,m;
int dist[N][N];

void floyd(){
    REP(k,1,n+1){
        REP(i,1,n+1){
            REP(j,1,n+1){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); //floyd模板
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)&&(n||m)){
        FILL(dist,0x3f);
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dist[u][v]=dist[v][u]=w; //无向图初始化边权
        }
        floyd();
        cout<<dist[1][n]<<endl;
    }
}
