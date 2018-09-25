/*
For the daily milking, Farmer John's N cows (1 ≤ N ≤ 50,000) always line up in the same order. 
One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. 
To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. 
However, for all the cows to have fun they should not differ too much in height.
Farmer John has made a list of Q (1 ≤ Q ≤ 200,000) potential groups of cows and their heights (1 ≤ height ≤ 1,000,000). 
For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

Input
Line 1: Two space-separated integers, N and Q. 
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i 
Lines N+2..N+Q+1: Two integers A and B (1 ≤ A ≤ B ≤ N), representing the range of cows from A to B inclusive.
Output
Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.

Input
6 3
1
7
3
4
2
5
1 5
4 6
2 2
Output
6
3
0
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
const int N=50050;
struct node{
    int l,r,mmax,mmin;
}segTree[N<<2];
int a[N];
int n;
int mmax,mmin;

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){
        segTree[i].mmax=segTree[i].mmin=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    segTree[i].mmax=max(segTree[i<<1].mmax,segTree[(i<<1)|1].mmax);
    segTree[i].mmin=min(segTree[i<<1].mmin,segTree[(i<<1)|1].mmin);
}

void query(int i,int l,int r){
    if(segTree[i].mmax<=mmax&&segTree[i].mmin>=mmin) return;
    if(segTree[i].l==l&&segTree[i].r==r){
        mmax=max(mmax,segTree[i].mmax);
        mmin=min(mmin,segTree[i].mmin);
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid) query(i<<1,l,r);
    else if(l>mid) query((i<<1)|1,l,r);
    else{
        query(i<<1,l,mid);
        query((i<<1)|1,mid+1,r);
    }
}

int main(){
    int q;
    scanf("%d%d",&n,&q);
    REP(i,1,n+1) scanf("%d",&a[i]);
    build(1,1,n);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        mmax=-INF;
        mmin=INF;
        query(1,a,b); //最值查询
        printf("%d\n",mmax-mmin);
    }
}
