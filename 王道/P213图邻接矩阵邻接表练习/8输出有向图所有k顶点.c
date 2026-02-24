int printVertices(Graph G){//邻接矩阵存储，输出k顶点，返回个数
    int indegree,outdegree,k,m,count=0;
    for(k=0;k<G.numVertex;k++){//遍历顶点
        indegree = outdegree = 0;
        for(m=0;m<G.numVertex;m++)
            outdegree+=G.edge[k][m];//计算出度
        for(m=0;m<G.numVertex;m++)
            indegree+=G.edge[m][k];//计算入度
        if(outdegree>indegree){
            printf("%c",G.VerticesList[k]);
            count++;
        }
    }
    return count;
}