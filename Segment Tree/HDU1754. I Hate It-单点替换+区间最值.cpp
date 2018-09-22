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
