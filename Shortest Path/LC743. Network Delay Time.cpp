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
    struct compare{
        bool operator()(const PII& a,const PII& b){return a.second>b.second;};  
    };
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    
        unordered_map<int,vector<PII>> adj;
        REP(i,0,times.size()){
            VI edge=times[i];
            adj[edge[0]].push_back(MP(edge[1],edge[2]));
        }
        priority_queue<PII,vector<PII>,compare> pq;
        pq.push(MP(K,0));
        unordered_map<int,int> dist;
        int res=0;
        while(!pq.empty()){
            PII cur=pq.top();pq.pop();
            int u=cur.first,w=cur.second;
            if(dist.find(u)==dist.end()) dist[u]=w;
            if(adj.find(u)!=adj.end()){
                for(PII edge:adj[u]){
                    int v=edge.first,nw=edge.second;
                    if(dist.find(v)==dist.end()) pq.push(MP(v,w+nw));
                }
            }
        }
        if(dist.size()!=N) return -1;
        for(auto d:dist) res=max(res,d.second);
        return res;
    }
};
