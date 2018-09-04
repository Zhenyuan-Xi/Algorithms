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
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
//------------------------------------------------

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        unordered_map<int,unordered_set<int>> adj;
        unordered_map<int,int> indegree;
        REP(i,0,numCourses) indegree[i]=0;
        REP(i,0,prerequisites.size()){
            int u=prerequisites[i].second,v=prerequisites[i].first;
            if(adj[u].find(v)==adj[u].end()){
                adj[u].insert(v);
                indegree[v]++;
            }
        }
        queue<int> q;
        int res=0;
        REP(i,0,numCourses){
            if(indegree[i]==0){
                q.push(i);
                res++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            REP(i,0,size){
                int u=q.front();q.pop();
                for(int v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        res++;
                        q.push(v);
                    }
                }
            }
        }
        if(res!=numCourses) return false;
        return true;
    }
};
