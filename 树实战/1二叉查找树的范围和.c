//力扣938

int rangeSumBST(struct TreeNode* root,int low,int high){
    int rangeSumBST(struct TreeNode* root, int low, int high) {
    if(root == NULL)return 0;//递归的终点
    if(root->val > high)return rangeSumBST(root->left,low,high);
    else if(root->val < low)return rangeSumBST(root->right,low,high);
    else //root肯定在范围内了
        return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
}
}