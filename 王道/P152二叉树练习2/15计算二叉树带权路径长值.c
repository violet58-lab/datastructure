typedef struct node{
    int weight;
    struct node *left,*right;
}BTree;//方法一
int WPL(BTree *root){
    return WPL1(root,0);
}
int WPL1(BTree *root,int d){//d为深度
    if(root->left==NULL&&root->right==NULL)
        return (roo->weight*d);
    else
        return (WPL1(root->left,d+1)+WPL(root->right,d+1));
}
//方法二
int WPL(BTree *root){
    int w_l,w_r;
    if(root->left==NULL&&root->right==NULL)
        return 0;
    else
    {
        w_l=WPL(root->left);
        w_r=WPL(root->right);
        root->weight=root->left->weight+root->right->weight;
        return (w_l+w_r+root->weight);
    }
}