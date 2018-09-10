/*
Consider yourself lucky! Consider yourself lucky to be still breathing and having fun participating in this contest. 
But we apprehend that many of your descendants may not have this luxury. For, as you know, we are the dwellers of one of the most polluted cities on earth. 
Pollution is everywhere, both in the environment and in society and our lack of consciousness is simply aggravating the situation.
However, for the time being, we will consider only one type of pollution - the sound pollution. 
The loudness or intensity level of sound is usually measured in decibels and sound having intensity level 130 decibels or higher is considered painful. 
The intensity level of normal conversation is 6065 decibels and that of heavy traffic is 7080 decibels.
Consider the following city map where the edges refer to streets and the nodes refer to crossings.
The integer on each edge is the average intensity level of sound (in decibels) in the corresponding street.

                  90
               B-------E
              / \       \
          50 /   \ 120   \ 40
            /     \       \
           A       D-------G
            \       \  70 /
          60 \    80 \   / 140
              \       \ /
               C-------F
                   50

To get from crossing A to crossing G you may follow the following path: A-C-F-G. In that case you must be capable of tolerating sound intensity as high as 140 decibels. 
For the paths A-B-E-G,A-B-D-G and A-C-F-D-G you must tolerate respectively 90, 120 and 80 decibels of sound intensity.
There are other paths, too. However, it is clear that A-C-F-D-G is the most comfortable path since it does not demand you to tolerate more than 80 decibels.
In this problem, given a city map you are required to determine the minimum sound intensity level you must be able to tolerate in order to get from a given crossing to another.

Input
The input may contain multiple test cases.
The first line of each test case contains three integers C(≤ 100), S(≤ 1000) and Q(≤ 10000) where C indicates the number of crossings 
(crossings are numbered using distinct integers ranging from 1 to C), S represents the number of streets and Q is the number of queries.
Each of the next S lines contains three integers: c1, c2 and d indicating that the average sound intensity level on the street connecting the crossings c1 and c2 (c1 ̸= c2) is d decibels.
Each of the next Q lines contains two integers c1 and c2 (c1 ̸= c2) asking for the minimum sound intensity level you must be able to tolerate in order to get from crossing c1 to crossing c2.
The input will terminate with three zeros form C, S and Q.
Output
For each test case in the input first output the test case number (starting from 1) as shown in the sample output. 
Then for each query in the input print a line giving the minimum sound intensity level(in decibels) you must be able to tolerate 
in order to get from the first to the second crossing in the query. 
If there exists no path between them just print the line “no path”. Print a blank line between two consecutive test cases.

Input
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
Output
Case #1
80
60
60
Case #2
40
no path
80
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
const int N=110;
int n,m,q,idx;
int dist[N][N];

void floyd(){
    REP(k,1,n+1){
        REP(i,1,n+1){
            REP(j,1,n+1){
                dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
}

int main(){
    idx=0;
    while(~scanf("%d%d%d",&n,&m,&q)&&(n||m||q)){
        idx++;
        FILL(dist,0x3f);
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            dist[u][v]=dist[v][u]=w;
        }
        cout<<"Case #"<<idx<<endl;
        floyd();
        while(q--){
            int u,v;
            scanf("%d%d",&u,&v);
            if(dist[u][v]==INF) cout<<"no path"<<endl;
            else cout<<dist[u][v]<<endl;
        }
        cout<<endl;
    }
}
