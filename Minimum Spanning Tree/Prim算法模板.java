public int prim(int n,int[][] edges){
    boolean[] vis=new boolean[n+1];
    int[] dist=new int[n+1];
    int u=1,res=0;
    vis[u]=true;
    for(int i=1;i<=n;i++){
        dist[i]=edges[u][i];
    }
    int mmin;
    for(int i=1;i<=n;i++){
        mmin=Integer.MAX_VALUE;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&mmin>dist[j]){
                mmin=dist[j];
                u=j;
            }
        }
        if(mmin==Integer.MAX_VALUE) return res;
        vis[u]=true;
        res+=mmin;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]>edges[u][j]) dist[j]=edges[u][j];
        }
    }
}
