/*
C国的死对头A国这段时间正在进行军事演习，所以C国间谍头子Derek和他手下Tidy又开始忙乎了。
A国在海岸线沿直线布置了N个工兵营地,Derek和Tidy的任务就是要监视这些工兵营地的活动情况。
由于采取了某种先进的监测手段，所以每个工兵营地的人数C国都掌握的一清二楚,每个工兵营地的人数都有可能发生变动，可能增加或减少若干人手,但这些都逃不过C国的监视。
中央情报局要研究敌人究竟演习什么战术,所以Tidy要随时向Derek汇报某一段连续的工兵营地一共有多少人,
例如Derek问:“Tidy,马上汇报第3个营地到第10个营地共有多少人!”Tidy就要马上开始计算这一段的总人数并汇报。
但敌兵营地的人数经常变动，而Derek每次询问的段都不一样，所以Tidy不得不每次都一个一个营地的去数，很快就精疲力尽了，
Derek对Tidy的计算速度越来越不满:"你个死肥仔，算得这么慢，我炒你鱿鱼!”Tidy想：“你自己来算算看，这可真是一项累人的工作!我恨不得你炒我鱿鱼呢!”
无奈之下，Tidy只好打电话向计算机专家Windbreaker求救,Windbreaker说：“死肥仔，叫你平时做多点acm题和看多点算法书，现在尝到苦果了吧!”
Tidy说："我知错了。。。"但Windbreaker已经挂掉电话了。Tidy很苦恼，这么算他真的会崩溃的，聪明的读者，你能写个程序帮他完成这项工作吗？
不过如果你的程序效率不够高的话，Tidy还是会受到Derek的责骂的.

Input
第一行一个整数T，表示有T组数据。
每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。
接下来每行有一条命令，命令有4种形式：
(1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30）
(2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）;
(3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数;
(4)End 表示结束，这条命令在每组数据最后出现;
每组数据最多有40000条命令
Output
对第i组数据,首先输出“Case i:”和回车,
对于每个Query询问，输出一个整数并回车,表示询问的段中的总人数,这个数保持在int以内。
 
Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 

Output
Case 1:
6
33
59
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
const int N=50010;
struct node{
    int l,r,sum;
}segTree[N*3];
char str[10];
int n;

void build(int i,int l,int r){
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r){ //叶节点
        scanf("%d",&segTree[i].sum);
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid); //建左树
    build((i<<1)|1,mid+1,r); //建右树
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum; //根节点的和等于左右子树节点的和相加
}

void update(int i,int idx,int val){
    segTree[i].sum+=val; //更新根节点
    if(segTree[i].l==segTree[i].r) return; //叶节点
    int mid=(segTree[i].l+segTree[i].r)>>1; 
    if(idx<=mid) update(i<<1,idx,val); //更新左树
    else update((i<<1)|1,idx,val); //更新右树
}

int query(int i,int l,int r){
    if(segTree[i].l==l&&segTree[i].r==r) return segTree[i].sum; //找到当前查询区间
    int mid=(segTree[i].l+segTree[i].r)>>1;
    int sum=0;
    if(l>mid) sum=query((i<<1)|1,l,r); //右树中查询
    else if(r<=mid) sum=query(i<<1,l,r); //左树中查询
    else sum=query(i<<1,l,mid)+query((i<<1)|1,mid+1,r); //累加左右子树中的区间
    return sum;
}

int main(){
    int t,x,y;cin>>t;
    REP(i,1,t+1){
        scanf("%d",&n);
        build(1,1,n);
        printf("Case %d:\n",i);
        while(scanf("%s",&str)){
            if(strcmp(str,"End")==0) break;
            scanf("%d%d",&x,&y);
            if(strcmp(str,"Add")==0) update(1,x,y);
            else if(strcmp(str,"Sub")==0) update(1,x,-y);
            else printf("%d\n",query(1,x,y));
        }
    }
}
