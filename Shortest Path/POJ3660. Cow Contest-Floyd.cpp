/*
N (1 ≤ N ≤ 100) cows, conveniently numbered 1..N, are participating in a programming contest. As we all know, some cows code better than others. 
Each cow has a certain constant skill rating that is unique among the competitors.
The contest is conducted in several head-to-head rounds, each between two cows. 
If cow A has a greater skill level than cow B (1 ≤ A ≤ N; 1 ≤ B ≤ N; A ≠ B), then cow A will always beat cow B.
Farmer John is trying to rank the cows by skill level. 
Given a list the results of M (1 ≤ M ≤ 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. 
It is guaranteed that the results of the rounds will not be contradictory.

Input
* Line 1: Two space-separated integers: N and M
* Lines 2..M+1: Each line contains two space-separated integers 
that describe the competitors and results (the first integer, A, is the winner) of a single round of competition: A and B
Output
* Line 1: A single integer representing the number of cows whose ranks can be determined
　
Input
5 5
4 3
4 2
3 2
1 2
2 5
Output
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
                dist[i][j]=dist[i][j]||(dist[i][k]&&dist[k][j]); //连通性floyd模板
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FILL(dist,0);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        dist[u][v]=1;
    }
    floyd(); //floyd求传递闭包
    int res=0;
    REP(i,1,n+1){
        int cnt=0;
        REP(j,1,n+1){
            if(i==j) continue;
            if(dist[i][j]||dist[j][i]) cnt++; //累计节点出度或入度
        }
        if(cnt==n-1) res++; //当节点出度+入度=n-1时,该节点的位置可以确定
    }
    cout<<res;
}
