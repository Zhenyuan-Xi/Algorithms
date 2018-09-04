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
