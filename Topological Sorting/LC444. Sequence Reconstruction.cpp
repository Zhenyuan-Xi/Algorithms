/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. 
The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. 
Reconstruction means building a shortest common supersequence of the sequences in seqs 
(i.e., a shortest sequence so that all sequences in seqs are subsequences of it). 
Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]
Output:
false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Input:
org: [1,2,3], seqs: [[1,2]]
Output:
false
Explanation:
The reconstructed sequence can only be [1,2].

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
Output:
true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
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

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    
        int n=org.size();
        unordered_map<int,unordered_set<int>> adj;
        unordered_map<int,int> indegree;
        bool valid=false;
        REP(i,0,seqs.size()){
            VI edge=seqs[i];
            if(edge.empty()) continue;
            valid=true;
            if(edge[0]<1||edge[0]>n) return false;
            REP(j,1,edge.size()){
                int u=edge[j-1],v=edge[j];
                if(v<1||v>n) return false;
                if(adj[u].find(v)==adj[u].end()){
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }
        if(!valid) return false;
        queue<int> q;
        int res=0;
        REP(i,1,n+1){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            if(size!=1) return false;
            REP(i,0,size){
                int u=q.front();q.pop();
                if(org[res++]!=u) return false;
                for(int v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
        }
        return res==n;
    }
};
