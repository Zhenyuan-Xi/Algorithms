/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
Output: "wertf"
Input:
[
  "z",
  "x",
  "z"
] 
Output: "" 
Explanation: The order is invalid, so return "".
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
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
//------------------------------------------------

class Solution {
public:
    string alienOrder(vector<string>& words) {
    
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        for(string word:words) for(char c:word) indegree[c]=0;
        REP(i,1,words.size()){
            string first=words[i-1],second=words[i];
            REP(j,0,min(first.size(),second.size())){
                char u=first[j],v=second[j];
                if(u!=v){
                    if(adj[u].find(v)==adj[u].end()){
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        string res="";
        for(unordered_map<char,int>::iterator it=indegree.begin();it!=indegree.end();it++){
            if(it->second==0){
                q.push(it->first);
                res+=it->first;
            }
        }
        while(!q.empty()){
            int size=q.size();
            REP(i,0,size){
                char u=q.front();q.pop();
                for(char v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        res+=v;
                        q.push(v);
                    }
                }
            }
        }
        if(res.size()!=indegree.size()) return "";
        return res;
    }
};
