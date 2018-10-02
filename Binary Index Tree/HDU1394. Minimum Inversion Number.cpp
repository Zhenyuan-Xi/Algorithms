/*
The inversion number of a given number sequence a1, a2, ..., an is the number of pairs (ai, aj) that satisfy i < j and ai > aj.
For a given sequence of numbers a1, a2, ..., an, if we move the first m >= 0 numbers to the end of the seqence, 
we will obtain another sequence. There are totally n such sequences as the following:
a1, a2, ..., an-1, an (where m = 0 - the initial seqence)
a2, a3, ..., an, a1 (where m = 1)
a3, a4, ..., an, a1, a2 (where m = 2)
...
an, a1, a2, ..., an-1 (where m = n-1)
You are asked to write a program to find the minimum inversion number out of the above sequences.

Input
The input consists of a number of test cases. Each case consists of two lines: the first line contains a positive integer n (n <= 5000); 
the next line contains a permutation of the n integers from 0 to n-1.
Output
For each case, output the minimum inversion number on a single line.
 
Input
10
1 3 6 9 0 8 5 7 4 2
Output
16
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
const int N=5050;
int a[N];
int c[N];
int n;

int lowbit(int x){
    return x&(-x);
}

void update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=val;
    }
}

int query(int x){
    int res=0;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=c[i];
    }
    return res;
}

int main(){
    while(~scanf("%d",&n)){
        int sum=0;
        FILL(a,0);
        FILL(c,0);
        REP(i,1,n+1){
            scanf("%d",&a[i]);
            a[i]++; //下标从1开始
            sum+=query(n)-query(a[i]); //之前加入的在区间[a[i]...n]的数,即构成逆序对
            update(a[i],1); //数量加1
        }
        int res=sum;
        REP(i,1,n+1){
            sum+=n-a[i]-(a[i]-1); //将a[i]从首位移动到末位时,
            res=min(res,sum);
        }
        printf("%d\n",res);
    }
}
