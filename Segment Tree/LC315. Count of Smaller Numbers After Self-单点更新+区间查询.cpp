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
class Solution {
public:
    struct node{
        int l,r,cnt;
    }segTree[50010<<2];
    
    void build(int i,int l,int r){
        segTree[i].l=l;
        segTree[i].r=r;
        segTree[i].cnt=0;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build((i<<1)|1,mid+1,r);
    }
    
    void update(int i,int idx){
        segTree[i].cnt++;
        if(segTree[i].l==segTree[i].r) return;
        int mid=(segTree[i].l+segTree[i].r)>>1;
        if(idx<=mid) update(i<<1,idx);
        else update((i<<1)|1,idx);
    }
    
    int query(int i,int l,int r){
        if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].cnt;
        int res=0;
        int mid=(segTree[i].l+segTree[i].r)>>1;
        if(l>mid) res=query((i<<1)|1,l,r);
        else if(r<=mid) res=query(i<<1,l,r);
        else res=query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
        return res;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) return nums;
        VI sorted=nums;
        sort(ALL(sorted));
        unordered_map<int,int> mp;
        REP(i,0,sorted.size()) mp[sorted[i]]=i+1;
        build(1,0,sorted.size());
        RREP(i,nums.size()-1,0){
            int id=mp[nums[i]];
            nums[i]=query(1,0,id-1);
            update(1,id);
        }
        return nums;
    }
};
