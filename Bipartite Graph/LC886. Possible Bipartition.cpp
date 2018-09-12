/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.
Note:
1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
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

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        VII adj(N+1,VI());
        for(VI dislike:dislikes){
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        int colors[N+1];
        FILL(colors,0);
        REP(i,1,N+1){
            if(colors[i]==0&&!bfs(adj,colors,i,1)) return false;
        }
        return true;
    }
    
    bool bfs(VII& adj,int colors[],int i,int color){
        queue<int> q;
        q.push(i);
        colors[i]=color;
        while(!q.empty()){
            int size=q.size();
            color=-color;
            REP(i,0,size){
                int u=q.front();q.pop();
                for(int v:adj[u]){
                    if(!colors[v]){
                        colors[v]=color;
                        q.push(v);
                    }else if(colors[v]!=color) return false;
                }
            }
        }
        return true;
    }
};
