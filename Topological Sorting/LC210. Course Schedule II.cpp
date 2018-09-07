/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    
        VI res;
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
        REP(i,0,numCourses){
            if(indegree[i]==0){
                res.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            REP(i,0,size){
                int u=q.front();q.pop();
                for(int v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        res.push_back(v);
                        q.push(v);
                    }
                }
            }
        }
        if(res.size()!=numCourses) return VI();
        return res;
    }
};
