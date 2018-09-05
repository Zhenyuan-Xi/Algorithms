/*
There are N robots standing on the ground (Don't know why. Don't know how). 
Suddenly the sky turns into gray, and lightning storm comes! Unfortunately, one of the robots is stuck by the lightning!
So it becomes overladen. Once a robot becomes overladen, it will spread lightning to the near one.
The spreading happens when: 
  Robot A is overladen but robot B not.
  The Distance between robot A and robot B is no longer than R.
  No other robots stand in a line between them.
In this condition, robot B becomes overladen. 
We assume that no two spreading happens at a same time and no two robots stand at a same position. 
The problem is: How many kind of lightning shape if all robots is overladen? The answer can be very large so we output the answer modulo 10007. 
If some of the robots cannot be overladen, just output -1.
即给定各点坐标,在限制条件下求生成树的个数。

Input
There are several cases.
The first line is an integer T (T < = 20), indicate the test cases.
For each case, the first line contains integer N ( 1 < = N < = 300 ) and R ( 0 < = R < = 20000 ), indicate there stand N robots; 
following N lines, each contains two integers ( x, y ) ( -10000 < = x, y < = 10000 ), indicate the position of the robot. 
Output
One line for each case contains the answer.

Input
3
3 2
-1 0
0 1
1 0
3 2
-1 0
0 0
1 0
3 1
-1 0
0 1
1 0
Output
3
1
-1
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

const int M=10007;
const int N=301;
int mat[N][N];

struct point{
    int x,y;
}p[N]; //构造点

int det(int n){ //求n阶矩阵的行列式的值
    int res=1;
    REP(i,0,n) REP(j,0,n) mat[i][j]%=M;
    REP(i,0,n){
        REP(j,i+1,n){
            while(mat[j][i]){ //初等变换转化为上三角矩阵
                int temp=mat[i][i]/mat[j][i];
                REP(k,i,n) mat[i][k]=(mat[i][k]-mat[j][k]*temp)%M;
                swap(mat[i],mat[j]);
                res=-res;
            }
        }
        if(mat[i][i]==0) return 0;
        res=res*mat[i][i]%M; //累积主对角线的值
    }
    return (res+M)%M;
}

bool same(point i,point k,point j){ //判断ijk三点共线,且k点在ij两点之间
    return (i.x-j.x)*(k.y-j.y)==(k.x-j.x)*(i.y-j.y)
    &&min(i.x,j.x)<=k.x&&max(i.x,j.x)>=k.x
    &&min(i.y,j.y)<=k.y&&max(i.y,j.y)>=k.y;
}

int main(){
    int t,n,r;
    cin>>t;
    while(t--){
        FILL(mat,0);
        cin>>n>>r;
        REP(i,0,n) scanf("%d%d",&p[i].x,&p[i].y);
        REP(i,0,n){
            REP(j,i+1,n){
                if(sqrt(pow((p[i].x-p[j].x),2)+pow((p[i].y-p[j].y),2))<=r){ //判断距离是否合格
                    bool valid=true;
                    REP(k,0,n){
                        if(k!=i&&k!=j&&same(p[i],p[k],p[j])) valid=false; //检查三点共线
                    }
                    if(valid){
                        mat[i][j]=mat[j][i]=-1; //Kirchhoff矩阵=度数矩阵-邻接矩阵,即邻接矩阵添加负号
                        mat[i][i]++; //连通两点,度数矩阵加1
                        mat[j][j]++;
                    }
                }
            }
        }
        int res=det(n-1);
        res=res?res:-1;
        cout<<res<<endl;
    }
}
