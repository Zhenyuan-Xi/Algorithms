/*
Bessie wants to navigate her spaceship through a dangerous asteroid field in the shape of an N x N grid (1 <= N <= 500). 
The grid contains K asteroids (1 <= K <= 10,000), which are conveniently located at the lattice points of the grid. 
Fortunately, Bessie has a powerful weapon that can vaporize all the asteroids in any given row or column of the grid with a single shot.
This weapon is quite expensive, so she wishes to use it sparingly.Given the location of all the asteroids in the field, 
find the minimum number of shots Bessie needs to fire to eliminate all of the asteroids.
Input
* Line 1: Two integers N and K, separated by a single space. 
* Lines 2..K+1: Each line contains two space-separated integers R and C (1 <= R, C <= N) denoting the row and column coordinates of an asteroid, respectively.
Output
* Line 1: The integer representing the minimum number of times Bessie must shoot.

Input
3 4
1 1
1 3
2 2
3 2
Output
2
Hint
INPUT DETAILS: 
The following diagram represents the data, where "X" is an asteroid and "." is empty space: 
X.X 
.X. 
.X. 
OUTPUT DETAILS: 
Bessie may fire across row 1 to destroy the asteroids at (1,1) and (1,3), and then she may fire down column 2 to destroy the asteroids at (2,2) and (3,2).
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
const int N=510;
int mat[N][N];
int vis[N];
int link[N];
int n;

bool hungarian(int u){
    REP(v,1,n+1){
        if(mat[u][v]&&!vis[v]){
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
    int k;
    scanf("%d%d",&n,&k);
    while(k--){
        int r,c;
        scanf("%d%d",&r,&c);
        mat[r][c]=1; //将行和列抽象成节点,图中的行星则是连接行和列的边,即行和列分属于两个点集构成二分图,求最小点覆盖,注意只需要其中一条边即可
                     //若用两条边,则mat[r][c+n]=1,mat[c+n][r]=1,最后结果res/2
    }
    FILL(link,0);
    int res=0;
    REP(i,1,n+1){
        FILL(vis,0);
        if(hungarian(i)) res++;
    }
    cout<<res<<endl;
}
