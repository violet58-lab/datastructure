void Convert(Graph &G,int arcs[M][N]){将图G转为邻接矩阵
    for(i=0;i<n;i++){//遍历头结点
        p=(G->vertex[i]).next;//取第一条边
        while(p != NULL){
            arcs[i][p->nextvertex]=1;
            p = p->next;
        }
    }
}