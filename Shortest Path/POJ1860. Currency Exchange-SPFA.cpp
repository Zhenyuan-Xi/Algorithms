/*
Several currency exchange points are working in our city. Let us suppose that each point specializes in two particular currencies and performs exchange operations only with these currencies. 
There can be several points specializing in the same pair of currencies. Each point has its own exchange rates, exchange rate of A to B is the quantity of B you get for 1A. 
Also each exchange point has some commission, the sum you have to pay for your exchange operation. Commission is always collected in source currency. 
For example, if you want to exchange 100 US Dollars into Russian Rubles at the exchange point, 
where the exchange rate is 29.75, and the commission is 0.39 you will get (100 - 0.39) * 29.75 = 2963.3975RUR. 
You surely know that there are N different currencies you can deal with in our city. Let us assign unique integer number from 1 to N to each currency. 
Then each exchange point can be described with 6 numbers: integer A and B - numbers of currencies it exchanges, 
and real RAB, CAB, RBA and CBA - exchange rates and commissions when exchanging A to B and B to A respectively. 
Nick has some money in currency S and wonders if he can somehow, after some exchange operations, increase his capital. 
Of course, he wants to have his money in currency S in the end. Help him to answer this difficult question. 
Nick must always have non-negative sum of money while making his operations. 

Input
The first line of the input contains four numbers: N - the number of currencies, M - the number of exchange points, S - the number of currency Nick has 
and V - the quantity of currency units he has. The following M lines contain 6 numbers each - the description of the corresponding exchange point - in specified above order. 
Numbers are separated by one or more spaces. 1<=S<=N<=100, 1<=M<=100, V is real number, 0<=V<=103. 
For each point exchange rates and commissions are real, given with at most two digits after the decimal point, 10-2<=rate<=102, 0<=commission<=102. 
Let us call some sequence of the exchange operations simple if no exchange point is used more than once in this sequence. 
You may assume that ratio of the numeric values of the sums at the end and at the beginning of any simple sequence of the exchange operations will be less than 104. 

Output
If Nick can increase his wealth, output YES, in other case output NO to the output file.

Input
3 2 1 20.0
1 2 1.00 1.00 1.00 1.00
2 3 1.10 1.00 1.10 1.00
Output
YES
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define RREP(i,s,t) for(int i=(s);i>=(t);i--)
#define ALL(x) (x).begin(),(x).end()
#define FILL(x,v) memset(x,v,sizeof(x))
#define LEN(x) sizeof(x)/sizeof(x[0])
#define MP(x,y) make_pair(x,y)
const int INF=0x3f3f3f3f;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
/*----------------------------------------------*/
const int N=105;
struct node{
    int to,next;
    double r,c;
}mat[2*N];
double dist[N];
int vis[N];
int head[N];
int cnt[N];
int n;
int idx;
int m,s;
double unit;
bool flg;

void addEdge(int a,int b,double r,double c){
    mat[idx].next=head[a];
    mat[idx].to=b;
    mat[idx].r=r;
    mat[idx].c=c;
    head[a]=idx++;
}

void spfa(int u){
    queue<int> q;
    dist[u]=unit;
    vis[u]=1;
    cnt[u]++;
    q.push(u);
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=mat[i].next){
            int v=mat[i].to;
            double r=mat[i].r,c=mat[i].c;
            if(dist[v]<(dist[u]-c)*r){
                dist[v]=(dist[u]-c)*r;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]++;
                    if(cnt[v]>=n){flg=true;return;} //节点v入队次数超过n则存在环,即节点v的值可无限增大
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%lf",&n,&m,&s,&unit);
    idx=1;
    FILL(head,-1);
    REP(i,0,m){
        int a,b;
        double rab,cab,rba,cba;
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
        addEdge(a,b,rab,cab);
        addEdge(b,a,rba,cba);
    }
    FILL(dist,0);
    FILL(vis,0);
    FILL(cnt,0);
    spfa(s);
    if(flg) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
