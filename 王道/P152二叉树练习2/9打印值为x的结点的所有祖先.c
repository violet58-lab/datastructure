typedef struct{
    Node t;
    int tag;//tag=0左结点被访问，tag=1右节点被访问
}stack;
void search(Node root,E x){
    stack s[];
    top=0;
    while(root != NULL || top>0){
        while(root != NULL&&root->element!=x){//结点入栈
            s[++top].t=root;
            s[top].tag=0;//tag=0表示还没访问右子树
            root=root->left;
        }
        if(root !=NULL&&root->element==x){//找到x
            for(i=1;i<=top;i++)
                printf("%c",s[i].t->element);
                exit(1);
        }
        while(top!=0&&s[top].tag==1)//退栈(当前节点左右都访问过了)
            top--;//只要栈顶节点已经没有任何子树可走，就不断弹出
        if(top!=0){//转向右子树
            s[top].tag=1;
            root=s[top].t->right;
        }
    }
}