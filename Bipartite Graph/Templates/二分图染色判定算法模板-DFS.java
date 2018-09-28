class Solution{
    public List<List<Integer>> bipartite(int n,int[][] inputs){
        List<List<Integer>> res=new ArrayList<>();
        for(int i=0;i<2;i++){
            res.add(new ArrayList<>());
        }
        List<Integer>[] adj=new ArrayList[n];
        for(int i=0;i<n;i++){
            adj[i]=new ArrayList<>();
        }
        for(int[] input:inputs){
            int u=input[0],v=input[1];
            adj[u].add(v);
            adj[v].add(u);
        }
        int[] colors=new int[n];
        Arrays.fill(colors,-1);
        boolean ok=true;
        for(int i=0;i<n;i++){
            if(colors[i]==-1) dfs(res,adj,colors,i,0,ok);
        }
        if(!ok) return new ArrayList<>();
        else return res;
    }
    
    private void dfs(List<List<Integer>> res,List<Integer>[] adj,int[] colors,int i,int color,boolean ok){
        if(!ok) return;
        if(colors[i]!=-1){
            ok=colors[i]==color;
            return;
        }
        colors[i]=color;
        res.get(color).add(i);
        for(int j=0;j<adj[i].size();j++){
            dfs(res,adj,colors,adj[i].get(j),color^1,ok);
        }
    }
}

/*
测试用例
Input
4 2
1 2
2 3
Output
2 
1 3 4
*/
