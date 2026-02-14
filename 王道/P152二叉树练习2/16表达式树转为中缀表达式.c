void BtreeToE(BTree *root){
    BtreeToExp(root,1);
}
void BtreeToExp(BTree *root,int d){
    if(root==NULL)return;
    else if(root->left==NULL&&root->right==NULL)
        printf("%s",root->data);//若为叶节点，输出
    else{
        if(d>1)printf("(");//若有子表达式，则加一层括号
        RtreeToExp(root->left,d+1);
        printf("%s",root->data);
        BtreeToExp(root->right,d+1);
        if(d>1)printf(")");
    }
}