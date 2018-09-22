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
        ll start,end;
    }segTree[50050];
    
    void build(int i,int l,int r){
        segTree[i].l=l;
        segTree[i].r=r;
        segTree[i].cnt=0;
        segTree[i].start=a[l];
        segTree[i].end=a[r];
        if(l==r) return;
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build((i<<1)|1,mid+1,r);
    }
    
    void update(int i,ll t){
        if(segTree[i].l==segTree[i].r){
            if(segTree[i].start<=t&&segTree[i].end>=t) segTree[i].cnt++;
            return;
        }
        if(segTree[i].start<=t&&segTree[i].end>=t){
            segTree[i].cnt++;
            update(i<<1,t);
            update((i<<1)|1,t);
        }
    }
    
    int query(int i,ll lower,ll upper){
        if(segTree[i].l==segTree[i].r){
            if(segTree[i].start>=lower&&segTree[i].end<=upper) return segTree[i].cnt;
            if(segTree[i].start>upper||segTree[i].end<lower) return 0;
        }
        if(segTree[i].start>=lower&&segTree[i].end<=upper) return segTree[i].cnt;
        if(segTree[i].start>upper||segTree[i].end<lower) return 0;
        return query(i<<1,lower,upper)+query((i<<1)|1,lower,upper);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return 0;
        unordered_set<ll> sums;
        ll sum=0;
        REP(i,0,nums.size()){
            sum+=(ll)nums[i];
            sums.insert(sum);
        }
        for(ll val:sums) a.push_back(val);
        sort(ALL(a));
        build(1,0,a.size()-1);
        int res=0;
        RREP(i,nums.size()-1,0){
            update(1,sum);
            sum-=(ll)nums[i];
            res+=query(1,(ll)(sum+lower),(ll)(sum+upper));
        }
        return res;
    }

private:
    VI a;
};
