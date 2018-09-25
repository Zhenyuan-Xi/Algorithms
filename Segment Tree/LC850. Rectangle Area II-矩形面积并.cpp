/*
We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , 
where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.
Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.

Example 2:
Input: [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.

Note:
1 <= rectangles.length <= 200
rectanges[i].length = 4
0 <= rectangles[i][j] <= 10^9
The total area covered by all rectangles will never exceed 2^63 - 1 and thus will fit in a 64-bit signed integer.
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
const int N=440;
const int M=1e9+7;

class Solution {
public:
    struct line{
        int x,y1,y2,flg;
    }lines[N];
    static bool cmp(line a,line b){return a.x<b.x;}
    int y[N];
    struct node{
        int l,r,cover;
        ll len;
    }segTree[N<<2];
    
    void build(int i,int l,int r){
        segTree[i]=(node){y[l],y[r],0,0};
        if(l+1==r) return;
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build((i<<1)|1,mid,r);
    }
    
    void cal_len(int i){
        if(segTree[i].cover>0){
            segTree[i].len=segTree[i].r-segTree[i].l;
            return;
        }
        if(segTree[i].l+1==segTree[i].r) segTree[i].len=0;
        else segTree[i].len=segTree[i<<1].len+segTree[(i<<1)|1].len;
    }
    
    void update(int i,line e){
        if(segTree[i].l==e.y1&&segTree[i].r==e.y2){
            segTree[i].cover+=e.flg;
            cal_len(i);
            return;
        }
        if(e.y2<=segTree[i<<1].r) update(i<<1,e);
        else if(e.y1>=segTree[(i<<1)|1].l) update((i<<1)|1,e);
        else{
            line temp=e;
            temp.y2=segTree[i<<1].r;
            update(i<<1,temp);
            temp=e;
            temp.y1=segTree[(i<<1)|1].l;
            update((i<<1)|1,temp);
        }
        cal_len(i);
    }
    
    int rectangleArea(vector<vector<int>>& rec) {
        int n=rec.size(),tot=1;
        REP(i,0,n){
            int x1=rec[i][0],y1=rec[i][1],x2=rec[i][2],y2=rec[i][3];
            lines[tot]=(line){x1,y1,y2,1};
            y[tot]=y1;
            tot++;
            lines[tot]=(line){x2,y1,y2,-1};
            y[tot]=y2;
            tot++;
        }
        sort(lines+1,lines+tot,cmp);
        sort(y+1,y+tot);
        build(1,1,tot-1);
        update(1,lines[1]);
        ll res=0;
        REP(i,2,tot){
            res=(res+segTree[1].len*(lines[i].x-lines[i-1].x))%M;
            update(1,lines[i]);
        }
        return (int)res;
    }
};
