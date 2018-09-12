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

class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        
        List<Integer>[] adj=new ArrayList[N+1];
        for(int i=0;i<=N;i++){
            adj[i]=new ArrayList<>();
        }
        for(int[] dislike:dislikes){
            adj[dislike[0]].add(dislike[1]);
            adj[dislike[1]].add(dislike[0]);
        }
        int[] colors=new int[N+1];
        for(int i=0;i<=N;i++){
            if(colors[i]==0&&!dfs(adj,colors,i,1)) return false;
        }
        return true;
    }
    
    private boolean dfs(List<Integer>[] adj,int[] colors,int i,int color){
        if(colors[i]!=0) return colors[i]==color;
        colors[i]=color;
        for(int j:adj[i]){
            if(!dfs(adj,colors,j,-color)) return false;
        }
        return true;
    }
}
