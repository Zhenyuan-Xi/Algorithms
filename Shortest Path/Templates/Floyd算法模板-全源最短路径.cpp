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
const int N=1010;
int n,m;
int dist[N][N];

void floyd(){
    REP(k,1,n+1){ //k作为最外层循环
        REP(i,1,n+1){
            REP(j,1,n+1){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); //floyd求最短路径模板
            }
        }
    }
}

void print(){ //打印全源最短路径
    REP(i,1,n+1){
        REP(j,i+1,n+1){
            cout<<i<<"--"<<j<<":"<<(dist[i][j]==INF?-1:dist[i][j])<<endl;
        }
    }
    cout<<endl;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        FILL(dist,0x3f); //初始化距离矩阵
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dist[u][v]=dist[v][u]=w; //初始化无向图
        }
        floyd();
        print();
    }    
}

/*
测试用例
Input
3 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
Output
1--2:3
1--3:-1
2--3:-1

1--2:5
1--3:2
2--3:5
*/
