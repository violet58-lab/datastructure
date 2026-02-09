int Btdepth(TreeNode T){
    if(!T){
        return 0;
        int front=-1,rear=-1;
        int last=0,level=0;
        TreeNode Q[Maxsize];
        Q[++rear]=T;//根结点入队
        TreeNode p;
        while(front<rear){//队不空就循环
            p=Q[++front];//结点出队
            if(p->left)Q[++rear]=p->left;//左孩子入队
            if(p->right)Q[++rear]=p->right;//右孩子入队
            if(front==last){level+=1;last=rear;}
        }
    }return level;
}