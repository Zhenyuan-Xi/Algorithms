/*
It is well known that it is not easy to select courses in the college, for there is usually conflict among the time of the courses. 
Li Ming is a student who loves study every much, and at the beginning of each term, he always wants to select courses as more as possible. 
Of course there should be no conflict among the courses he selects. 
There are 12 classes every day, and 7 days every week. There are hundreds of courses in the college, and teaching a course needs one class each week. 
To give students more convenience, though teaching a course needs only one class, a course will be taught several times in a week. 
For example, a course may be taught both at the 7-th class on Tuesday and 12-th class on Wednesday, you should assume that there is no difference between the two classes, 
and that students can select any class to go. At the different weeks, a student can even go to different class as his wish. 
Because there are so many courses in the college, selecting courses is not an easy job for Li Ming. As his good friends, can you help him? 

Input
The input contains several cases. For each case, the first line contains an integer n (1 <= n <= 300), the number of courses in Li Ming's college. 
The following n lines represent n different courses. In each line, the first number is an integer t (1 <= t <= 7*12), the different time when students can go to study the course. 
Then come t pairs of integers p (1 <= p <= 7) and q (1 <= q <= 12), which mean that the course will be taught at the q-th class on the p-th day of a week.
Output
For each test case, output one integer, which is the maximum number of courses Li Ming can select.

Input
5
1 1 1
2 1 1 2 2
1 2 2
2 3 2 3 3
1 3 3
Output
4
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>

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
const int M=50010;
struct edge{
    int to,next;
}edges[M];
int head[N],tot;
int vis[N];
int link[N];
int n;

void init(){
    tot=0;
    FILL(head,-1);
}

void addEdge(int u,int v){
    edges[tot].to=v;
    edges[tot].next=head[u];
    head[u]=tot++;
}

bool hungarian(int u){
    for(int i=head[u];~i;i=edges[i].next){
        int v=edges[i].to;
        if(!vis[v]){
            vis[v]=1;
            if(!link[v]||hungarian(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(~scanf("%d",&n)){
        init();
        REP(i,1,n+1){
            int t;
            scanf("%d",&t);
            while(t--){
                int p,q;
                scanf("%d%d",&p,&q);
                addEdge(i,(p-1)*12+q); //以课程号和课程时间(需要hash)为两个点集划分二分图,寻找最大匹配
            }
        }
        FILL(link,0);
        int res=0;
        REP(i,1,n+1){
            FILL(vis,0);
            if(hungarian(i)) res++;
        }
        cout<<res<<endl;
    }
}
