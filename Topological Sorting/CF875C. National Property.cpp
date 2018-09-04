/*
The alphabet of Bookland is so large that its letters are denoted by positive integers. 
Each letter can be small or large, the large version of a letter x is denoted by x'. 
BSCII encoding, which is used everywhere in Bookland, is made in that way so that large letters are presented in the order of the numbers they are denoted by, 
and small letters are presented in the order of the numbers they are denoted by, but all large letters are before all small letters. 
For example, the following conditions hold: 2 < 3, 2' < 3', 3' < 2.
A word x1, x2, ..., xa is not lexicographically greater than y1, y2, ..., yb if one of the two following conditions holds:
    1. a ≤ b and x1 = y1, ..., xa = ya, i.e. the first word is the prefix of the second word;
    2. there is a position 1 ≤ j ≤ min(a, b), such that x1 = y1, ..., xj - 1 = yj - 1 and xj < yj, 
       i.e. at the first position where the words differ the first word has a smaller letter than the second word has.
For example, the word "3' 7 5" is before the word "2 4' 6" in lexicographical order. 
It is said that sequence of words is in lexicographical order if each word is not lexicographically greater than the next word in the sequence.

Denis has a sequence of words consisting of small letters only. He wants to change some letters to large (let's call this process a capitalization) in such a way 
that the sequence of words is in lexicographical order. However, he soon realized that for some reason he can't change a single letter in a single word. 
He only can choose a letter and change all of its occurrences in all words to large letters. 
He can perform this operation any number of times with arbitrary letters of Bookland's alphabet.
Help Denis to choose which letters he needs to capitalize (make large) in order to make the sequence of words lexicographically ordered, or determine that it is impossible.
Note that some words can be equal.

Input
The first line contains two integers n and m (2 ≤ n ≤ 100 000, 1 ≤ m ≤ 100 000) — the number of words and the number of letters in Bookland's alphabet, respectively. 
The letters of Bookland's alphabet are denoted by integers from 1 to m.
Each of the next n lines contains a description of one word in format li, si, 1, si, 2, ..., si, li (1 ≤ li ≤ 100 000, 1 ≤ si, j ≤ m), 
where li is the length of the word, and si, j is the sequence of letters in the word. The words are given in the order Denis has them in the sequence.
It is guaranteed that the total length of all words is not greater than 100000.

Output
In the first line print "Yes" (without quotes), if it is possible to capitalize some set of letters in such a way 
that the sequence of words becomes lexicographically ordered. Otherwise, print "No" (without quotes).
If the required is possible, in the second line print k — the number of letters Denis has to capitalize (make large), 
and in the third line print k distinct integers — these letters. Note that you don't need to minimize the value k.
You can print the letters in any order. If there are multiple answers, print any of them.

Input
4 3
1 2
1 1
3 1 3 2
2 1 1
Output
Yes
2
2 3

Input
6 5
2 1 2
2 1 2
3 1 2 3
2 1 5
2 4 4
2 4 4
Output
Yes
0

Input
4 3
4 3 2 2 1
3 1 1 3
3 2 3 3
2 3 1
Output
No
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
/*----------------------------------------------*/

bool is_prefix(VI first,VI second){
    REP(i,0,first.size()){
        if(i==second.size()) return true;
        if(first[i]!=second[i]) return false;
    }
    return false;
}

void dfs(unordered_map<int,unordered_set<int>>& adj,int cap[],int u){
    for(int v:adj[u]){
        if(cap[v]==2){cout<<"No";exit(0);}
        if(cap[v]==0){
            cap[v]=1;
            dfs(adj,cap,v);
        }
    }
}

int main(){
    int n,m,l,val;cin>>n>>m;
    VII words(n);
    REP(i,0,n){
        cin>>l;
        REP(j,0,l){
            cin>>val;
            words[i].push_back(val);
        }
    }
    /*
    u=first[j],v=second[j],若u<v,则v->u;否则cap[u]=1,cap[v]=2
    从cap[v]=1的节点开始DFS遍历,若邻节点u=2,则v<u不符合邻接表里的v>u;u=1,合理;u=0,标记cap[u]=1,并从u开始DFS遍历
    */
    unordered_map<int,unordered_set<int>> adj;
    int cap[m+1]; //0:no state,1:must capitalize,2:cannot capitalize
    FILL(cap,0);
    VI res;
    REP(i,1,n){
        VI first=words[i-1],second=words[i];
        if(first.size()>second.size()&&is_prefix(first,second)){cout<<"No";return 0;}
        REP(j,0,min(first.size(),second.size())){
            int u=first[j],v=second[j];
            if(u<v) {adj[v].insert(u);break;}
            if(u>v){
                if(cap[u]==2||cap[v]==1){cout<<"No";return 0;}
                cap[u]=1;
                cap[v]=2;
                break;
            }
        }
    }
    REP(i,1,m+1){
        if(cap[i]==1) dfs(adj,cap,i);
    }
    REP(i,1,m+1){
        if(cap[i]==1) res.push_back(i);
    }
    cout<<"Yes"<<endl;
    cout<<res.size()<<endl;
    REP(i,0,res.size()) cout<<res[i]<<" ";
}
