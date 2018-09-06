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

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        VI dist(n,INF);
        VI prev;
        dist[src]=0;
        REP(i,0,K+1){
            prev=dist;
            for(VI edge:flights){
                int u=edge[0],v=edge[1],w=edge[2];
                dist[v]=min(dist[v],prev[u]+w);
            }
        }
        return dist[dst]==INF?-1:dist[dst];
    }
};
