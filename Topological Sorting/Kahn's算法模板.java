public void Kahn(int n, int[][] edges){
    Map<Integer,Set<Integer>> adj=new HashMap<>();
    Map<Integer,Integer> indegree=new HashMap<>();
    for(int i=0;i<edges.length;i++){
        int u=edges[i][0],v=edges[i][1];
        if(!indegree.containsKey(u)) indegree.push(u,0);
        adj.pushIfAbsent(u,new HashSet<>());
        if(!adj[u].contains(v)){
            adj[u].add(v);
            indegree.put(v,indegree.getOrDefault(v,0)+1);
        }
    }
    Queue<Integer> q=new LinkedList<>();
    int cnt=0;
    for(int i:indegree.keySet()){
        if(indegree.get(i)==0) q.offer(i);
    }
    while(!q.isEmpty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int u=q.poll();
            cnt++;
            for(int v:adj.get(u)){
                indegree.put(v,indegree.get(v)-1);
                if(indegree.get(v)==0) q.offer(v);
            }
        }
    }
    if(cnt!=n) System.out.println("Not Valid");
    else System.out.println("Valid");
}
