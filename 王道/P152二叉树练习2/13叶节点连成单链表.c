ListNode head,pre=NULL;
ListNode Inorder(TreeNode root){
    if(root){
        Inorder(root->left);//中序遍历左子树
        if(root->left==NULL&&root->right==NULL)
            if(pre==NULL){
                head=root;
                pre=root;//处理第一个叶节点
            }else{
                pre->right=root;
                pre=root;
            }//将叶节点链入链表
        Inorder(root->right);//中序遍历右子树
        pre->right=NULL;//设置链表尾
    }
    return head;
}