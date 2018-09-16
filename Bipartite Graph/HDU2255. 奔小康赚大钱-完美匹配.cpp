/*
传说在遥远的地方有一个非常富裕的村落,有一天,村长决定进行制度改革：重新分配房子。
这可是一件大事,关系到人民的住房问题啊。村里共有n间房间,刚好有n家老百姓,考虑到每家都要有房住（如果有老百姓没房子住的话，容易引起不安定因素），每家必须分配到一间房子且只能得到一间房子。
另一方面,村长和另外的村领导希望得到最大的效益,这样村里的机构才会有钱.由于老百姓都比较富裕,他们都能对每一间房子在他们的经济范围内出一定的价格,
比如有3间房子,一家老百姓可以对第一间出10万,对第2间出2万,对第3间出20万.(当然是在他们的经济范围内).现在这个问题就是村领导怎样分配房子才能使收入最大.
(村民即使有钱购买一间房子但不一定能买到,要看村领导分配的).
 
Input
输入数据包含多组测试用例，每组数据的第一行输入n,表示房子的数量(也是老百姓家的数量)，接下来有n行,每行n个数表示第i个村名对第j间房出的价格(n<=300)。
Output
请对每组数据输出最大的收入值，每组的输出占一行。
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
const int N=310;
int mat[N][N];
int visx[N];
int visy[N];
int lx[N];
int ly[N];
int link[N];
int slack[N];
int n;

void init(){
    FILL(link,0);
    FILL(ly,0);
    REP(u,1,n+1){
        lx[u]=-INF;
        REP(v,1,n+1) lx[u]=max(lx[u],mat[u][v]);
    }
}

bool find(int u){
    visx[u]=1;
    REP(v,1,n+1){
        if(visy[v]) continue;
        int gap=lx[u]+ly[v]-mat[u][v];
        if(gap==0){
            visy[v]=1;
            if(!link[v]||find(link[v])){
                link[v]=u;
                return true;
            }
        }else slack[v]=min(slack[v],gap);
    }
    return false;
}

int km(){
    init();
    REP(u,1,n+1){
        FILL(slack,0x3f);
        while(1){
            FILL(visx,0);
            FILL(visy,0);
            if(find(u)) break;
            int d=INF;
            REP(i,1,n+1){
                if(!visy[i]) d=min(d,slack[i]);
            }
            REP(i,1,n+1){
                if(visx[i]) lx[i]-=d; 
                if(visy[i]) ly[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    REP(u,1,n+1){
        res+=mat[link[u]][u];
    }
    return res;
}

int main(){
    while(~scanf("%d",&n)){
        REP(u,1,n+1){
            REP(v,1,n+1){
                int w;
                scanf("%d",&w);
                mat[u][v]=w;
            }
        }
        int res=km();
        cout<<res<<endl;
    }
}
