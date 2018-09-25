/*
There are several ancient Greek texts that contain descriptions of the fabled island Atlantis. 
Some of these texts even include maps of parts of the island. But unfortunately, these maps describe different regions of Atlantis. 
Your friend Bill has to know the total area for which maps exist. You (unwisely) volunteered to write a program that calculates this quantity.
 
Input
The input file consists of several test cases. Each test case starts with a line containing a single integer n (1<=n<=100) of available maps. 
The n following lines describe one map each. Each of these lines contains four numbers x1;y1;x2;y2 (0<=x1<x2<=100000;0<=y1<y2<=100000), not necessarily integers. 
The values (x1; y1) and (x2;y2) are the coordinates of the top-left resp. bottom-right corner of the mapped area.
The input file is terminated by a line containing a single 0. Don’t process it.
Output
For each test case, your program should output one section. The first line of each section must be “Test case #k”, where k is the number of the test case (starting with 1). 
The second one must be “Total explored area: a”, where a is the total explored area (i.e. the area of the union of all rectangles in this test case), 
printed exact to two digits to the right of the decimal point.
Output a blank line after each test case.
 
Input
2
10 10 20 20
15 15 25 25.5
0
Output
Test case #1
Total explored area: 180.00
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
const int N=220;
//扫描线从左往右,构建y轴上的区间线段,将其加入线段树并计算当前x轴位置的y轴长度
struct line{
    double x,y1,y2; 
    int flg; //标记区间进入或离开
}lines[N];
double y[N];
struct node{
    int l,r,cover; //cover标记当前区间覆盖的个数
    double len,lf,rf; //当前区间的y轴长度和实际的左右浮点数边界
}segTree[N<<2];
int n;
int iCase=0;

bool cmp(line a,line b){return a.x<b.x;}

void build(int i,int l,int r){
    segTree[i]=(node){l,r,0,0,y[l],y[r]};
    if(l+1==r) return;
    int mid=(l+r)>>1;
    build(i<<1,l,mid); 
    build((i<<1)|1,mid,r); //建连续区间,即(10,20)->(10,15),(15,20)
}

void cal_len(int i){
    if(segTree[i].cover>0){
        segTree[i].len=segTree[i].rf-segTree[i].lf;
        return;
    }
    if(segTree[i].l+1==segTree[i].r) segTree[i].len=0;
    else segTree[i].len=segTree[i<<1].len+segTree[(i<<1)|1].len;
}

void update(int i,line e){
    if(segTree[i].lf==e.y1&&segTree[i].rf==e.y2){
        segTree[i].cover+=e.flg;
        cal_len(i);
        return;
    }
    if(e.y2<=segTree[i<<1].rf) update(i<<1,e);
    else if(e.y1>=segTree[(i<<1)|1].lf) update((i<<1)|1,e);
    else{
        line temp=e;
        temp.y2=segTree[i<<1].rf;
        update(i<<1,temp);
        temp=e;
        temp.y1=segTree[(i<<1)|1].lf;
        update((i<<1)|1,temp);
    }
    cal_len(i);
}

int main(){
    while(~scanf("%d",&n)&&n){
       ++iCase;
       int tot=1;
       printf("Test case #%d\n",iCase);
       REP(i,1,n+1){
           double x1,y1,x2,y2;
           scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
           lines[tot]=(line){x1,y1,y2,1}; //矩形左边界线段进入
           y[tot]=y1;
           tot++;
           lines[tot]=(line){x2,y1,y2,-1}; //矩形右边界线段离开
           y[tot]=y2;
           tot++;
       }
       sort(lines+1,lines+tot,cmp); //将区间线段按x轴排序
       sort(y+1,y+tot); //实际浮点值排序,与线段树区间对应
       build(1,1,tot-1);
       update(1,lines[1]); //将第一条线段加入线段树
       double res=0;
       REP(i,2,tot){
           res+=segTree[1].len*(lines[i].x-lines[i-1].x); //计算dx*当前x轴位置y轴长度
           update(1,lines[i]); //将该线段加入线段树
       }
       printf("Total explored area: %.2lf\n\n",res);
    }
}
