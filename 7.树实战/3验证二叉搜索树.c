//力扣98题
//考虑右子树中左子树比根节点还小的情况！写上上界与下界
bool isValid(struct TreeNode* root,long min,long max){
    if(root == NULL)return true;
    if(root->left != NULL && (root->left->val >= root->val || root->left->val <= min))
        return false;
    if(root->right != NULL && (root->right->val <= root->val || root->right->val >= max))
        return false;
    return isValid(root->left,min,root->val)&&isValid(root->right,root->val,max);
}
bool isValidBST(struct TreeNode* root) {
    return isValid(root,-2147483649,2147483648);
}