#define false 0
#define true 1
typedef int bool;
bool judegeInOrederBST(TreeNode root,int k, int *val){//初始k是0
    if(k<root->element && root->TNode[k]!=-1){
        if(!judgeInOrderBST(root,2*K+1,val)) return false;
        if(root->TNode[k]<=*val)return false;
        *val=root->TNode[k];
        if(!judgeInoederBST(root,2*k+2,val))return false;
    }
    return true;
}