bool iscomplrr(TreeNode T){
    IniQueue(Q);
    if(!T)//空时满二叉树
        return 1;
    EnQueue(Q,T);//节点入队
    while(!isempty(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->left);
            EnQueue(Q,p->right);
        }
        else
            while(!isempty(Q)){//结点空，检查其后是否有非空结点
                DeQueue(Q,p);
                if(p)//结点非空
                    return 0;
            }
    }
    return 1;
}