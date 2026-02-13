void DelteTree(Node root){
    if(root){
        DelteTree(root->left);
        DelteTree(root->right);
        free(root);
    }
}
void search(Node root,E x){
    Node Q[];//Q为存放二叉树结点指针的队列
    if(root){
        if(root->element==x){
            DelteTree(root);
            exit(0);
        }
        InitQueue(Q);
        EnQueue(Q,root);
        while(!isempty(Q)){
            DeQueue(Q,p);
            if(p->left)//左子树非空
                if(p->left->element){//左子树符合则删
                    DeleteTree(p->left);
                    p->NULL;
                }
                else//左子树不符合则入队
                    EnQueue(Q,p->left);
            if(p->right)
                if(p->right->element == x){
                    DeleteTree(p->right);
                    p->right=NULL;
                }
                else
                    EnQueue(Q,p->right);
        }
    }
}