//LCR 124
//某二叉树的先序遍历结果记录于整数数组 preorder，它的中序遍历结果记录于整数数组 inorder。
//请根据 preorder 和 inorder 的提示构造出这棵二叉树并返回其根节点。

//1.前序遍历首元素为根节点，首先得到根节点
//2.在中序遍历序列中寻找根节点的位置
//3.将左右序列分割开来，并重构根节点左右子树(递归分治)
//4.在新的序列中，重复上述步骤，通过前序遍历再次找到当前子树根节点，再次分割
//5.直到分割仅剩下一个结点时，开始回溯，从而完成整棵二叉树的重建
struct TreeNode * createNode(int val){
    struct TreeNode * node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

struct TreeNode* buildTreeCore(int* preorder,int* inorder,int start,int end,int index){//index是开始的位置
    if(start > end)return NULL;
    if(start == end)return createNode(preorder[index]);//不可划分，返回此结点
    struct TreeNode *node = createNode(preorder[index]);
    int pos = 0;
    while(inorder[pos] != preorder[index])pos++;
    node->left = buildTreeCore(preorder,inorder,start,pos-1,index+1);//划分左边
    node->right = buildTreeCore(preorder,inorder,pos+1,end,index+(pos-start)+1);
    return node;
}

struct TreeNode* deduceTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return buildTreeCore(preorder,inorder,0,preorderSize-1,0);
}