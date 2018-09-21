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
struct node{
    int l,r,sum;
}segTree[50050];

class NumArray {
public:
    NumArray(vector<int> nums) {
        int n=nums.size();
        if(n==0) return;
        a.push_back(-1);
        REP(i,0,nums.size()){
            a.push_back(nums[i]);
        }
        build(1,1,n);
    }
    
    void build(int i,int l,int r){
        segTree[i].l=l;
        segTree[i].r=r;
        if(l==r){
            segTree[i].sum=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build((i<<1)|1,mid+1,r);
        segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
    }
    
    void update(int i, int val) {
        update(1,i+1,val);
    }
    
    int update(int i,int idx,int val){
        int diff;
        if(segTree[i].l==segTree[i].r){ //叶节点为当前需要被替换的节点
            diff=val-segTree[i].sum; //记录差值并向上传递
            segTree[i].sum=val;
            return diff;
        }
        int mid=(segTree[i].l+segTree[i].r)>>1;
        if(idx<=mid) diff=update(i<<1,idx,val);
        else diff=update((i<<1)|1,idx,val);
        segTree[i].sum+=diff; //区间和更新差值
        return diff;
    }
    
    int sumRange(int i, int j) {
        return query(1,i+1,j+1);
    }
    
    int query(int i,int l,int r){
        if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].sum;
        int mid=(segTree[i].l+segTree[i].r)>>1;
        int sum=0;
        if(l>mid) sum=query((i<<1)|1,l,r);
        else if(r<=mid) sum=query(i<<1,l,r);
        else sum=query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
        return sum;
    }

private:
    VI a;
};
