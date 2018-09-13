/*
Moriarty has trapped n people in n distinct rooms in a hotel. Some rooms are locked, others are unlocked. 
But, there is a condition that the people in the hotel can only escape when all the doors are unlocked at the same time. 
There are m switches. Each switch control doors of some rooms, but each door is controlled by exactly two switches.
You are given the initial configuration of the doors. Toggling any switch, that is, turning it ON when it is OFF, or turning it OFF when it is ON, 
toggles the condition of the doors that this switch controls. Say, we toggled switch 1, which was connected to room 1, 2 and 3 which were respectively locked, unlocked and unlocked. 
Then, after toggling the switch, they become unlocked, locked and locked.
You need to tell Sherlock, if there exists a way to unlock all doors at the same time.

Input
First line of input contains two integers n and m (2 ≤ n ≤ 105, 2 ≤ m ≤ 105) — the number of rooms and the number of switches.
Next line contains n space-separated integers r1, r2, ..., rn (0 ≤ ri ≤ 1) which tell the status of room doors. 
The i-th room is locked if ri = 0, otherwise it is unlocked.
The i-th of next m lines contains an integer xi (0 ≤ xi ≤ n) followed by xi distinct integers separated by space, 
denoting the number of rooms controlled by the i-th switch followed by the room numbers that this switch controls. 
It is guaranteed that the room numbers are in the range from 1 to n. It is guaranteed that each door is controlled by exactly two switches.
Output
Output "YES" without quotes, if it is possible to open all doors at the same time, otherwise output "NO" without quotes.

Input
3 3
1 0 1
2 1 3
2 1 2
2 2 3
Output
NO

Input
3 3
1 0 1
3 1 2 3
1 2
2 1 3
Output
YES

Input
3 3
1 0 1
3 1 2 3
2 1 2
1 3
Output
NO

Note
In the second example input, the initial statuses of the doors are [1, 0, 1] (0 means locked, 1 — unlocked).
After toggling switch 3, we get [0, 0, 0] that means all doors are locked.
Then, after toggling switch 1, we get [1, 1, 1] that means all doors are unlocked.
It can be seen that for the first and for the third example inputs it is not possible to make all doors unlocked.
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
const int N=1e5+10;
int states[N]; //每扇门的状态
VI stwich[N]; //每扇门对应的两个开关
vector<PII> edges[N]; //开关之间的边,开关u和v由门的状态决定,若门为0,则u和v属于不同集合,否则u和v属于同一集合,构成二分图,即edges[u]=(v,states[i])
int colors[N]; 
int n,m;
bool ok;

void dfs(int u,int color){
    if(!ok) return;
    if(colors[u]!=-1){
        ok=colors[u]==color;
        return;
    }
    colors[u]=color;
    REP(i,0,edges[u].size()){
        int v=edges[u][i].first,w=edges[u][i].second;
        // (color,state)->new color: 0,0->1  0,1->0  1,0->0  1,1->1
        dfs(v,1-(color^w));
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FILL(colors,-1);
    ok=true;
    REP(i,1,n+1){
        scanf("%d",&states[i]);
    }
    REP(i,1,m+1){
        int j,k;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&j);
            stwich[j].push_back(i); //stwich[门]=(开关u,开关v)
        }
    }
    REP(i,1,n+1){
        int u=stwich[i][0],v=stwich[i][1];
        edges[u].push_back(MP(v,states[i])); //edges[开关u]=(开关v,门状态)
        edges[v].push_back(MP(u,states[i])); //edges[开关v]=(开关u,门状态)
    }
    REP(i,1,m+1){
        if(colors[i]==-1) dfs(i,0);
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}
