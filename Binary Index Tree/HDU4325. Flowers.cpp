/*
As is known to all, the blooming time and duration varies between different kinds of flowers. 
Now there is a garden planted full of flowers. The gardener wants to know how many flowers will bloom in the garden in a specific time. 
But there are too many flowers in the garden, so he wants you to help him.
 
Input
The first line contains a single integer t (1 <= t <= 10), the number of test cases.
For each case, the first line contains two integer N and M, where N (1 <= N <= 10^5) is the number of flowers, and M (1 <= M <= 10^5) is the query times. 
In the next N lines, each line contains two integer Si and Ti (1 <= Si <= Ti <= 10^9), means i-th flower will be blooming at time [Si, Ti].
In the next M lines, each line contains an integer Ti, means the time of i-th query.
Output
For each case, output the case number as shown and then print M lines. Each line contains an integer, meaning the number of blooming flowers.
Sample outputs are available for more details.
 
Input
2
1 1
5 10
4
2 3
1 4
4 8
1
4
6
Output
Case #1:
0
Case #2:
1
2
1
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
const int N=200020;
int c[N]; //树状数组C数组
int a[N],tot; //离散化数组
int s[N],t[N]; 
int q[N];

int lowbit(int x){
    return x&(-x);
}

void update(int x,int val){
    for(int i=x;i<=tot;i+=lowbit(i)){
        c[i]+=val;
    }
}

ll query(int x){
    ll res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=c[i];
    }
    return res;
}

int Bin(int target,int tot){ 
    int l=0,r=tot-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]==target) return mid;
        else if(a[mid]>target) r=mid-1;
        else l=mid+1;
    }
}

int main(){
    int T,n,m;
    scanf("%d",&T);
    REP(iCase,1,T+1){
        printf("Case #%d:\n",iCase);
        scanf("%d%d",&n,&m);
        FILL(c,0);
        FILL(a,0);
        FILL(s,0);
        FILL(t,0);
        FILL(q,0);
        tot=0;
        REP(i,0,n){
            scanf("%d%d",&s[i],&t[i]);
            a[tot++]=s[i];
            a[tot++]=t[i];
        }
        REP(i,0,m){
            scanf("%d",&q[i]);
            a[tot++]=q[i];
        }
        sort(a,a+tot); //排序
        int tmp=tot;
        tot=1;
        REP(i,1,tmp){
            if(a[i]!=a[i-1]) a[tot++]=a[i]; //去重
        }
        REP(i,0,n){
            int l=Bin(s[i],tot)+1; //用二分查找在离散化数组中找到左边界
            int r=Bin(t[i],tot)+1; //用二分查找在离散化数组中找到右边界
            update(l,1); //区间[l...]增加1
            update(r+1,-1); //区间[r+1...]减去1,即区间[l...r]增加1
        }
        REP(i,0,m){
            int qu=Bin(q[i],tot)+1; //用二分在离散化数组中找到query点
            printf("%lld\n",query(qu));
        }
    }
}
