void judge_AVL(TreeNode root,int &balance,int &h){
    int bl=0,br=0,hl=0,hr=0;
    if(root==NULL){h=0;balance=1;}//为空
    else if(root->left==NULL && root->right==NULL){h=1;balance=1;}//仅有根节点
    else{//后序遍历
        judge_AVL(root->left,bl,hl);
        judge_AVL(root->right,br,hr);
        h=(hl>hr?hl:hr)+1;
        if(abs(hl-hr)<2)
            balance=bl&&br;//逻辑与(全真为真),判断平衡二叉树的，返回1
        else
            balance=0;
    }
}