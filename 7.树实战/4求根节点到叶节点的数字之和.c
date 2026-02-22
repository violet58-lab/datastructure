//129
int sumNumbersImpl(struct TreeNode* root,int parent) {
    if(root == NULL)return 0;
    int sum = root->val + parent *10;
    if(!root->left && !root->right)return sum;
    return sumNumbersImpl(root->left,sum)+sumNumbersImpl(root->right,sum);
}
int sumNumbers(struct TreeNode* root) {
    return sumNumbersImpl(root,0);
}