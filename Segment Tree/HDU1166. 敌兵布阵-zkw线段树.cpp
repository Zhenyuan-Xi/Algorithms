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
const int N=50010;
int segTree[N<<2];
int M,n;
char str[10];

void pushup(int i){
    segTree[i]=segTree[i<<1]+segTree[(i<<1)|1];
}

void build(){
    for(M=1;M<n;M<<=1);
    REP(i,M+1,M+n+1) scanf("%d",&segTree[i]);
    RREP(i,M,1) pushup(i);
}

void update(int idx,int val){
    for(segTree[idx+=M]+=val;idx>>=1;) pushup(idx);
}

int query(int l,int r){
    int res=0;
    for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1) res+=segTree[l^1];
        if(r&1) res+=segTree[r^1];
    }
    return res;
}

int main(){
    int t,x,y;cin>>t;
    REP(i,1,t+1){
        scanf("%d",&n);
        build();
        printf("Case %d:\n",i);
        while(scanf("%s",&str)){
            if(strcmp(str,"End")==0) break;
            scanf("%d%d",&x,&y);
            if(strcmp(str,"Add")==0) update(x,y);
            else if(strcmp(str,"Sub")==0) update(x,-y);
            else printf("%d\n",query(x,y));
        }
    }
}
