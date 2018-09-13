/*
Recently, Pari and Arya did some research about NP-Hard problems and they found the minimum vertex cover problem very interesting.
Suppose the graph G is given. Subset A of its vertices is called a vertex cover of this graph, 
if for each edge uv there is at least one endpoint of it in this set, i.e.  or  (or both).
Pari and Arya have won a great undirected graph as an award in a team contest. 
Now they have to split it in two parts, but both of them want their parts of the graph to be a vertex cover.
They have agreed to give you their graph and you need to find two disjoint subsets of its vertices A and B, 
such that both A and B are vertex cover or claim it's impossible. 
Each vertex should be given to no more than one of the friends (or you can even keep it for yourself).

Input
The first line of the input contains two integers n and m (2 ≤ n ≤ 100 000, 1 ≤ m ≤ 100 000) 
— the number of vertices and the number of edges in the prize graph, respectively.
Each of the next m lines contains a pair of integers ui and vi (1  ≤  ui,  vi  ≤  n), denoting an undirected edge between ui and vi. 
It's guaranteed the graph won't contain any self-loops or multiple edges.
Output
If it's impossible to split the graph between Pari and Arya as they expect, print "-1" (without quotes).
If there are two disjoint sets of vertices, such that both sets are vertex cover, print their descriptions. 
Each description must contain two lines. The first line contains a single integer k denoting the number of vertices in that vertex cover, 
and the second line contains k integers — the indices of vertices. Note that because of m ≥ 1, vertex cover cannot be empty.

Input
4 2
1 2
2 3
Output
1
2 
2
1 3
Input
3 3
1 2
2 3
1 3
Output
-1
Note
In the first sample, you can give the vertex number 2 to Arya and vertices numbered 1 and 3 to Pari and keep vertex number 4 for yourself 
In the second sample, there is no way to satisfy both Pari and Arya.
*/

#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
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
VI adj[N];
VI res[2];
int colors[N];
bool valid;

void dfs(int u,int color){
    if(!valid) return;
    if(colors[u]!=-1){
        valid=colors[u]==color;
        return;
    }
    colors[u]=color;
    res[color].push_back(u);
    REP(i,0,adj[u].size()){
        dfs(adj[u][i],color^1);
    }
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FILL(colors,-1);
    valid=true;
    REP(i,1,n+1){
        if(colors[i]==-1) dfs(i,0);
    }
    if(!valid) cout<<-1<<endl;
    else{
        cout<<res[0].size()<<endl;
        REP(i,0,res[0].size())
            cout<<res[0][i]<<" ";
        cout<<endl;
        cout<<res[1].size()<<endl;
        REP(i,0,res[1].size())
            cout<<res[1][i]<<" ";
        cout<<endl;
    }
}
