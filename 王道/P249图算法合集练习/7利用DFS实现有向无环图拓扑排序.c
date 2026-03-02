bool visited[MAX_VERTEX_NUM];//标记访问数组
void dfsraverse(Graph G){
    for(v=0;v<G.vexnum;++v)
        visited[v]=false;
    time=0;
    for(v=0;v<G.vexnum;++v)
        if(!visited)dfs(G,v);
}
void dfs(Grap,int v){
    visited[v]=true;
    visit(v);
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w]){//w为未被访问的结点
            dfs(G,w);
        }
    time += 1;
    finishtime[v]=time;
}   