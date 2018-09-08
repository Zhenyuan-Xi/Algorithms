/*
One day , Kiki wants to visit one of her friends. As she is liable to carsickness , she wants to arrive at her friend’s home as soon as possible . 
Now give you a map of the city’s traffic route, and the stations which are near Kiki’s home so that she can take. You may suppose Kiki can change the bus at any station. 
Please find out the least time Kiki needs to spend. To make it easy, if the city have n bus stations ,the stations will been expressed as an integer 1,2,3…n.

Input
There are several test cases. 
Each case begins with three integers n, m and s,(n<1000,m<20000,1=<s<=n) n stands for the number of bus stations in this city and m stands for the number of directed ways between bus stations .
(Maybe there are several ways between two bus stations .) s stands for the bus station that near Kiki’s friend’s home.
Then follow m lines ,each line contains three integers p , q , t (0<t<=1000). means from station p to station q there is a way and it will costs t minutes .
Then a line with an integer w(0<w<n), means the number of stations Kiki can take at the beginning. Then follows w integers stands for these stations.
Output
The output contains one line for each data set : the least time Kiki needs to spend ,if it’s impossible to find such a route ,just output “-1”.

Input
5 8 5
1 2 2
1 5 3
1 3 4
2 4 7
2 5 6
2 3 5
3 5 1
4 5 1
2
2 3
4 3 4
1 2 3
1 3 4
2 3 2
1
1
Output
1
-1
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
const int N=1010;
int mat[N][N];
int dist[N];
int n;
int vis[N];

void spfa(int u){
    queue<int> q;
    q.push(u);
    dist[u]=0;
    vis[u]=1;
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        REP(v,1,n+1){
            if(dist[v]>dist[u]+mat[u][v]){
                dist[v]=dist[u]+mat[u][v];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

int main(){
    int m,s,w;
    while(scanf("%d%d%d",&n,&m,&s)==3){
        FILL(mat,0x3f);
        FILL(dist,0x3f);
        FILL(vis,0);
        while(m--){
            int p,q,t;
            scanf("%d%d%d",&p,&q,&t);
            mat[p][q]=t;
        }
        cin>>w;
        while(w--){
            int a;
            cin>>a;
            mat[0][a]=0;
        }
        spfa(0);
        if(dist[s]==INF) cout<<-1<<endl;
        else cout<<dist[s]<<endl;
    }
}
