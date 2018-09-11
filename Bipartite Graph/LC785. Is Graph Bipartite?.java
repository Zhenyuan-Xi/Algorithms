/*
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B 
such that every edge in the graph has one node in A and another node in B.
The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
*/

class Solution{
    public boolean isBipartite(int[][] graph) {
        int n=graph.length;
        int[] colors=new int[n];
        for(int i=0;i<n;i++){
            if(colors[i]==0&&!dfs(graph,colors,i,1)) return false;
        }
        return true;
    }

    private boolean dfs(int[][] graph,int[] colors,int i,int color){
        if(colors[i]!=0) return colors[i]==color; //若当前节点有颜色且不等于当前该染的颜色,则与父节点颜色相同,不合法
        colors[i]=color; //染色
        for(int j:graph[i]){
            if(!dfs(graph,colors,j,-color)) return false; 
        }
        return true;
    }
}
