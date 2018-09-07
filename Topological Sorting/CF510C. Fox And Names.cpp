/*
Fox Ciel is going to publish a paper on FOCS (Foxes Operated Computer Systems, pronounce: "Fox"). 
She heard a rumor: the authors list on the paper is always sorted in the lexicographical order.
After checking some examples, she found out that sometimes it wasn't true. 
On some papers authors' names weren't sorted in lexicographical order in normal sense. 
But it was always true that after some modification of the order of letters in alphabet, the order of authors becomes lexicographical!
She wants to know, if there exists an order of letters in Latin alphabet such that the names on the paper 
she is submitting are following in the lexicographical order. If so, you should find out any such order.
Lexicographical order is defined in following way. When we compare s and t, first we find the leftmost position with differing characters: si ≠ ti. 
If there is no such position (i. e. s is a prefix of t or vice versa) the shortest string is less. 
Otherwise, we compare characters si and ti according to their order in alphabet.

Input
The first line contains an integer n (1 ≤ n ≤ 100): number of names.
Each of the following n lines contain one string namei (1 ≤ |namei| ≤ 100), the i-th name. 
Each name contains only lowercase Latin letters. All names are different.

Output
If there exists such order of letters that the given names are sorted lexicographically, output any such order as a permutation of characters 'a'–'z' 
(i. e. first output the first letter of the modified alphabet, then the second, and so on).
Otherwise output a single word "Impossible" (without quotes).

Input
3
rivest
shamir
adleman
Output
bcdefghijklmnopqrsatuvwxyz

Input
10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooooooo
subscriber
rowdark
tankengineer
Output
Impossible

Input
7
car
care
careful
carefully
becarefuldontforgetsomething
otherwiseyouwillbehacked
goodluck
Output
acbdefhijklmnogpqrstuvwxyz
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

int main(){
    int n;cin>>n;
    VS names(n);
    bool vis[26];
    FILL(vis,false);
    REP(i,0,n) cin>>names[i];
    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char,int> indegree;
    REP(i,1,n){
        string first=names[i-1],second=names[i];
        if(first.size()>second.size()&&first.find(second)==0){cout<<"Impossible";return 0;} //判断后一个string是否为前一个string的prefix，若是则无结果
        REP(j,0,min(first.size(),second.size())){
            int u=first[j],v=second[j];
            if(u!=v){
                if(indegree.find(u)==indegree.end()) indegree[u]=0;
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
        if(it->second==0) q.push(it->first);
    }
    while(!q.empty()){
        int size=q.size();
        REP(i,0,size){
            char u=q.front();q.pop();
            res+=u;
            vis[u-'a']=true;
            for(char v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
    }
    if(res.size()!=indegree.size()){cout<<"Impossible";return 0;}
    REP(i,0,26){
        if(!vis[i]) res+=i+'a';
    }
    cout<<res;
}
