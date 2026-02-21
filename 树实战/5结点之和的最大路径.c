//LCR 051
//路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。
//同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
int result = -2147483648;//定义全局变量
int max(int a,int b){
    return a > b ? a : b;
}

int maxValue(struct TreeNode* root){
    if(root == NULL)return 0;
    //先把左右两边走或不走的情况计算一下，取出值最大的情况
    int leftMax = max(maxValue(root->left),0);
    int rightMax = max(maxValue(root->right),0);
    //要么左，要么右，要么左右都走，所以计算最大的情况
    int maxTmp = leftMax + rightMax + root->val;
    result = max(maxTmp,result);//更新最大值
    //从上面下来的情况，要么左要么右
    return max(leftMax,rightMax)+root->val;
}

int maxPathSum(struct TreeNode* root){
    maxValue(root);
    return result;
}