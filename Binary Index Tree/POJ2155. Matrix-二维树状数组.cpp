/*
Given an N*N matrix A, whose elements are either 0 or 1. A[i, j] means the number in the i-th row and j-th column. 
Initially we have A[i, j] = 0 (1 <= i, j <= N). 
We can change the matrix in the following way. Given a rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2), 
we change all the elements in the rectangle by using "not" operation (if it is a '0' then change it into '1' otherwise change it into '0'). 
To maintain the information of the matrix, you are asked to write a program to receive and execute two kinds of instructions. 
1.	C x1 y1 x2 y2 (1 <= x1 <= x2 <= n, 1 <= y1 <= y2 <= n) changes the matrix by using the rectangle 
whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2). 
2.	Q x y (1 <= x, y <= n) querys A[x, y]. 

Input
The first line of the input is an integer X (X <= 10) representing the number of test cases. The following X blocks each represents a test case. 
The first line of each block contains two numbers N and T (2 <= N <= 1000, 1 <= T <= 50000) representing the size of the matrix and the number of the instructions. 
The following T lines each represents an instruction having the format "Q x y" or "C x1 y1 x2 y2", which has been described above. 
Output
For each querying output one line, which has an integer representing A[x, y]. 
There is a blank line between every two continuous test cases. 

Input
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1
Output
1
0
0
1
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
const int N=1010;
int c[N][N];
int n;

int lowbit(int i){
    return i&(-i);
}

void update(int l,int r,int val){
    for(int i=l;i<=n;i+=lowbit(i))
        for(int j=r;j<=n;j+=lowbit(j))
            c[i][j]+=val;
}

int query(int l,int r){
    int ans=0;
    for(int i=l;i>0;i-=lowbit(i))
        for(int j=r;j>0;j-=lowbit(j))
            ans+=c[i][j];
    return ans;
}

int main(){
    int X;
    scanf("%d",&X);
    REP(iCase,1,X+1){
        int t;
        scanf("%d%d",&n,&t);
        FILL(c,0);
        char op[10];
        int x1,x2,y1,y2;
        while(t--){
            scanf("%s",op);
            if(op[0]=='C'){
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                update(x2+1,y2+1,1); 
                update(x2+1,y1,1);
                update(x1,y2+1,1);
                update(x1,y1,1); //增加反转次数,即目标区域反转次数增加1,其余区域反转次数增加2即未反转
            }else{
                scanf("%d%d",&x1,&y1);
                if(query(x1,y1)%2==0) printf("0\n");
                else printf("1\n");
            }
        }
        printf("\n");
    }
}
