int DsonNodes(TreeNode b){
    if(b==NULL)return 0;
    else if(b->left && b->right)
        return DsonNodes(b->left)+DsonNodes(b->right)+1;
    else
        return DsonNodes(b->left)+DsonNodes(b->right);
}