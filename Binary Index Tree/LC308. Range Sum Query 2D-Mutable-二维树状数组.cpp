/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
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

class NumMatrix{
public:
    VII mat;
    VII BIT;
    
    NumMatrix(VII matrix){
        if(matrix.size()==0) return;
        int n=matrix.size(),m=matrix[0].size();
        mat=VII(n,VI(m,0));
        BIT=VII(n+1,VI(m+1,0));
        REP(i,0,n) REP(j,0,m) update(i,j,matrix[i][j]);
    }
    
    int lowbit(int i){
        return i&(-i);
    }
    
    void update(int row,int col,int val){
        for(int i=row+1;i<=mat.size();i+=lowbit(i))
            for(int j=col+1;j<=mat[0].size();j+=lowbit(j))
                BIT[i][j]+=val-mat[row][col];
        mat[row][col]=val;
    }
    
    int query(int row,int col){
        int ans=0;
        for(int i=row;i>0;i-=lowbit(i))
            for(int j=col;j>0;j-=lowbit(j))
                ans+=BIT[i][j];
        return ans;
    }
    
    int sumRegion(int row1,int col1,int row2,int col2){
        return query(row2+1,col2+1)-query(row2+1,col1)-query(row1,col2+1)+query(row1,col1);
    }
};
