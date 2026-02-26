bool isTree(Graph &G){
    for(int i=1;i<=G.vexnum;i++)
        visited[i]=false;//初始化，所有顶点都没有访问过
    int Vnum=0,Enum=0;
    dfs(G,1,Vnum,Enum,visited);
    if(Vnum==G.vexnum&&Enum==2*(G.vexnum-1))//邻接表里一条边会被记录2次
        return true;
    else
        return false;
}
void dfs(Graph &G,int v,int &Vnum,int &Enum,int visited[]){
    //深度优先遍历图G，统计访问过的定点数和边数，通过Vnum和Enum返回
    visited[v]=true;Vnum++;//访问当前结点
    int w=FirstNeighbor(G,v);//返回v邻接点
    while(w!=-1){//遍历所有邻接点
        Enum++;
        if(!visited[w])
            dfs(G,w,Vnum,Enum,visited);
        w=NextNeighbor(G,v,w);//返回除w之外x下一个邻接点
    }
}