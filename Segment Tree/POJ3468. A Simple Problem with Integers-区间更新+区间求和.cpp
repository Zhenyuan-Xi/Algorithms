/*
You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. 
One type of operation is to add some given number to each number in a given interval. 
The other is to ask for the sum of numbers in a given interval.

Input
The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.
Output
You need to answer all Q commands in order. One answer in a line.

Input
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Output
4
55
9
15
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
const int N=100010;
struct node{
    int l,r;
    ll lazy,sum; //区间更新使用lazy标记
}segTree[N<<2];
char str[10];
ll a[N];
int n;

void push_down(int i){ //lazy标记向下传递
    segTree[i<<1].sum+=(segTree[i<<1].r-segTree[i<<1].l+1)*segTree[i].lazy;
    segTree[i<<1].lazy+=segTree[i].lazy;
    segTree[(i<<1)|1].sum+=(segTree[(i<<1)|1].r-segTree[(i<<1)|1].l+1)*segTree[i].lazy;
    segTree[(i<<1)|1].lazy+=segTree[i].lazy;
    segTree[i].lazy=0;
}

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].lazy=0;
    if(l==r){
        segTree[i].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}

void update(int i,int l,int r,ll val){
    if(segTree[i].l==l&&segTree[i].r==r){ //叶节点更新
        segTree[i].lazy+=val;
        segTree[i].sum+=(r-l+1)*val;
        return;
    }
    if(segTree[i].l==segTree[i].r) return;
    if(segTree[i].lazy) push_down(i); //向子区间传递lazy标记
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid) update(i<<1,l,r,val);
    else if(l>mid) update((i<<1)|1,l,r,val);
    else{
        update(i<<1,l,mid,val);
        update((i<<1)|1,mid+1,r,val);
    }
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}

ll query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].sum; //找到当前查询区间
    if(segTree[i].lazy) push_down(i); //向子区间传递lazy标记
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid) return query(i<<1,l,r);
    else if(l>mid) return query((i<<1)|1,l,r);
    else return query(i<<1,l,mid)+query((i<<1)|1,mid+1,r);
}

int main(){
    int q;
    while(~scanf("%d%d",&n,&q)){
        REP(i,1,n+1) scanf("%lld",&a[i]);
        build(1,1,n);
        while(q--){
            int a,b,c;
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d%d%d",&a,&b,&c);
                update(1,a,b,c);
            }else{
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(1,a,b));
            }
        }
    }
}
