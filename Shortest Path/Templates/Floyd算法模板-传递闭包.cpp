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
    REP(k,1,n+1){
        REP(i,1,n+1){
            REP(j,1,n+1){
                dist[i][j]=dist[i][j]||(dist[i][k]&&dist[k][j]); //floyd传递闭包模板
            }
        }
    }
}

void print(){
    REP(i,1,n+1){
        REP(j,1,n+1){
            if(i==j) continue;
            cout<<i<<"->"<<j<<":"<<dist[i][j]<<endl; //打印各点连通性
        }
    }
    cout<<endl;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        FILL(dist,0); //初始化全源不连通
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            dist[u][v]=1; //有向图中初始化连通的两点
        }
        floyd();
        print();
    }
}

/*
测试用例
Input
5 5
4 3
4 2
3 2
1 2
2 5
Output
1->2:1
1->3:0
1->4:0
1->5:1
2->1:0
2->3:0
2->4:0
2->5:1
3->1:0
3->2:1
3->4:0
3->5:1
4->1:0
4->2:1
4->3:1
4->5:1
5->1:0
5->2:0
5->3:0
5->4:0
*/
