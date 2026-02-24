int IsExistEL(Graph G){//邻接矩阵存储
    int degree,i,j,count=0;
    for(i=0;i<G.numVertices;i++){
        degree=0;
        for(j=0;j<G.numsvertices;j++)
            degree+=G.Edge[i][j];
        if(degree%2!=0)
            count++;
    }
    if(count==0||count==2)
        return 1;
    else
        return 0;
}