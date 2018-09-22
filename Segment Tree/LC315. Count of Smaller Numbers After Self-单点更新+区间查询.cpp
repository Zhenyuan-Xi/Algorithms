/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Input: [5,2,6,1]
Output: [2,1,1,0] 

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
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
        REP(i,0,sorted.size()) mp[sorted[i]]=i+1; //排序后记录index
        build(1,0,sorted.size());
        RREP(i,nums.size()-1,0){ //从右往左遍历
            int id=mp[nums[i]]; //在排序数组里的index
            nums[i]=query(1,0,id-1); //在(0,id)内区间查询
            update(1,id); //单点更新,将该点以及孩子区间都更新,即(0,2):0->1,(1,2):0->1
        }
        return nums;
    }
};
