/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
You need to return the number of important reverse pairs in the given array.

Example1:
Input: [1,3,2,3,1]
Output: 2

Example2:
Input: [2,4,3,5,1]
Output: 3

Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
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
class Solution {
public:
    struct node{
        int l,r,cnt;
    }segTree[75050*4];
    
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
        if(segTree[i].l==segTree[i].r){
            segTree[i].cnt++;
            return;
        }
        int mid=(segTree[i].l+segTree[i].r)>>1;
        if(idx<=mid) update(i<<1,idx);
        else update((i<<1)|1,idx);
        segTree[i].cnt=segTree[i<<1].cnt+segTree[(i<<1)|1].cnt;
    }
    
    int query(int i,int l,int r){
        if(segTree[i].l>=l&&segTree[i].r<=r) return segTree[i].cnt;
        if(segTree[i].l>r||segTree[i].r<l) return 0;
        return query(i<<1,l,r)+query((i<<1)|1,l,r);
    }
    
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        set<ll> s;
        for(int num:nums){
            s.insert(num);
            s.insert(num*2L+1);
        }
        unordered_map<ll,int> mp;
        int i=0;
        for(ll num:s){
            mp[num]=i++;
        }
        build(1,0,s.size()-1);
        int res=0;
        for(int num:nums){
            int idx=mp[num*2L+1];
            res+=query(1,idx,s.size()-1);
            update(1,mp[num]);
        }
        return res;
    }
};
