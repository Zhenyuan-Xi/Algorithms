/*
很多学校流行一种比较的习惯。老师们很喜欢询问，从某某到某某当中，分数最高的是多少。这让很多学生很反感。
不管你喜不喜欢，现在需要你做的是，就是按照老师的要求，写一个程序，模拟老师的询问。当然，老师有时候需要更新某位同学的成绩。
 
Input
本题目包含多组测试，请处理到文件结束。
在每个测试的第一行，有两个正整数 N 和 M ( 0<N<=200000,0<M<5000 )，分别代表学生的数目和操作的数目。
学生ID编号分别从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩。
接下来有M行。每一行有一个字符 C (只取'Q'或'U') ，和两个正整数A，B。
当C为'Q'的时候，表示这是一条询问操作，它询问ID从A到B(包括A,B)的学生当中，成绩最高的是多少。
当C为'U'的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
Output
对于每一次询问操作，在一行里面输出最高成绩。
 
Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

Output
5
6
5
9
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
const int N=2e5+10;
struct node{
    int l,r,mmax;
}segTree[N<<2];
int n;

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        scanf("%d",&segTree[i].mmax);
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    segTree[i].mmax=max(segTree[i<<1].mmax,segTree[(i<<1)|1].mmax);
}

void update(int i,int idx,int val){
    if(segTree[i].l==segTree[i].r){ //找到叶节点,替换最值
        segTree[i].mmax=val;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(idx<=mid) update(i<<1,idx,val);
    else update((i<<1)|1,idx,val);
    segTree[i].mmax=max(segTree[i<<1].mmax,segTree[(i<<1)|1].mmax); //向上传递最值
}

int query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].mmax;
    int res=-INF;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(l>mid) res=query((i<<1)|1,l,r);
    else if(r<=mid) res=query(i<<1,l,r);
    else res=max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
    return res;
}

int main(){
    int m,x,y;
    while(~scanf("%d%d",&n,&m)){
        build(1,1,n);
        while(m--){
            char c[2];
            scanf("%s%d%d",c,&x,&y);
            if(c[0]=='U') update(1,x,y);
            else printf("%d\n",query(1,x,y));
        }
    }
}
